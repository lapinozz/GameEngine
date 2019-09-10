#include <assets.hpp>

#include <glad.hpp>

#include <anton_stl/vector.hpp>
#include <assets_internal.hpp>
#include <build_config.hpp>
#include <debug_macros.hpp> // CHECK_GL_ERRORS
#include <importers/obj.hpp>
#include <importers/png.hpp>
#include <importers/tga.hpp>
#include <math/vector3.hpp>
#include <mesh/mesh.hpp>
#include <opengl.hpp>
#include <paths.hpp>
#include <postprocess.hpp>
#include <shader.hpp>
#include <utils/filesystem.hpp>

#include <fstream>
#include <stdexcept>

namespace anton_engine::assets {
    std::string read_file_raw_string(std::filesystem::path const& filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::invalid_argument("Could not open file " + filename.string());
        }
        std::string out;
        std::getline(file, out, '\0');
        return out;
    }

    opengl::Shader_Type shader_type_from_filename(std::filesystem::path const& filename) {
        std::string extension(filename.extension().string());
        if (extension == ".vert") {
            return opengl::Shader_Type::vertex_shader;
        } else if (extension == ".frag") {
            return opengl::Shader_Type::fragment_shader;
        } else if (extension == ".geom") {
            return opengl::Shader_Type::geometry_shader;
        } else if (extension == ".comp") {
            return opengl::Shader_Type::compute_shader;
        } else if (extension == ".tese") {
            return opengl::Shader_Type::tessellation_evaluation_shader;
        } else if (extension == ".tesc") {
            return opengl::Shader_Type::tessellation_control_shader;
        } else {
            throw std::invalid_argument("\"" + extension + "\" is not a known shader file extension");
        }
    }

    Shader_File load_shader_file(std::filesystem::path const& path) {
        // TODO will not compile in shipping build
        std::filesystem::path full_path = utils::concat_paths(paths::shaders_directory(), path);
        std::string shader_source = read_file_raw_string(full_path);
        return Shader_File(path.generic_string(), shader_type_from_filename(path), shader_source);
    }

    static uint8_t read_uint8(std::ifstream& stream) {
        return stream.get();
    }

    static uint16_t read_uint16_le(std::ifstream& stream) {
        return static_cast<uint16_t>(read_uint8(stream)) | (static_cast<uint16_t>(read_uint8(stream)) << 8);
    }

    static uint32_t read_uint32_le(std::ifstream& stream) {
        return static_cast<uint32_t>(read_uint16_le(stream)) | (static_cast<uint32_t>(read_uint16_le(stream)) << 16);
    }

    static uint64_t read_uint64_le(std::ifstream& stream) {
        return static_cast<uint64_t>(read_uint32_le(stream)) | (static_cast<uint64_t>(read_uint32_le(stream)) << 32);
    }

    static int32_t read_int32_le(std::ifstream& stream) {
        return (stream.get()) | (stream.get() << 8) | (stream.get() << 16) | (stream.get() << 24);
    }

    static int64_t read_int64_le(std::ifstream& stream) {
        return (static_cast<int64_t>(read_int32_le(stream)) | static_cast<int64_t>(read_int32_le(stream)) << 32);
    }

    struct Texture {
        uint32_t width;
        uint32_t height;
        opengl::Format format;
        opengl::Sized_Internal_Format internal_format;
        opengl::Type type;
        opengl::Texture_Filter filter;
        uint64_t swizzle_mask;
        anton_stl::Vector<uint8_t> pixels;
    };

    // TODO extract writing and reading to one tu to keep them in sync
    static Texture load_texture_from_file(std::filesystem::path const& file_path, uint64_t const texture_id) {
        // TODO texture loading
        std::ifstream file(file_path, std::ios::binary);
        while (!file.eof()) {
            [[maybe_unused]] int64_t const texture_data_size = read_int64_le(file);
            uint64_t const tex_id = read_uint64_le(file);
            if (tex_id == texture_id) {
                Texture texture;
                texture.width = read_uint32_le(file);
                texture.height = read_uint32_le(file);
                texture.format = static_cast<opengl::Format>(read_int32_le(file));
                texture.internal_format = static_cast<opengl::Sized_Internal_Format>(read_int32_le(file));
                texture.type = static_cast<opengl::Type>(read_int32_le(file));
                texture.filter = static_cast<opengl::Texture_Filter>(read_int32_le(file));
                texture.swizzle_mask = read_uint64_le(file);
                int64_t texture_size_bytes = read_int64_le(file);
                texture.pixels.resize(texture_size_bytes);
                file.read(reinterpret_cast<char*>(texture.pixels.data()), texture_size_bytes);
                return texture;
            } else {
                // TODO shipping build texture loading
                // Since there's only one texture per file right now, we do not have to skip past it, but instead throw an exception
                throw std::runtime_error("Texture not found in the file " + file_path.generic_string());
            }
        }
        throw std::runtime_error("Invalid texture file");
    }

    static bool should_use_linear_magnififcation_filter(opengl::Texture_Filter const filter) {
        return filter == opengl::Texture_Filter::linear || filter == opengl::Texture_Filter::linear_mipmap_nearest ||
               filter == opengl::Texture_Filter::linear_mipmap_linear;
    }

    uint32_t load_texture(std::string const& filename, uint64_t const texture_id) {
#if !GE_BUILD_SHIPPING
        std::filesystem::path const texture_path = utils::concat_paths(paths::assets_directory(), filename + ".getex");
        Texture const texture = load_texture_from_file(texture_path, texture_id);
#else
// TODO shipping build texture loading
#endif
        uint32_t texture_gl_handle;
        opengl::gen_textures(1, &texture_gl_handle);
        opengl::bind_texture(opengl::Texture_Type::texture_2D, texture_gl_handle);
        opengl::tex_image_2D(GL_TEXTURE_2D, 0, texture.internal_format, texture.width, texture.height, texture.format, texture.type, texture.pixels.data());
        uint32_t const mag_filter = should_use_linear_magnififcation_filter(texture.filter) ? GL_LINEAR : GL_NEAREST;
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, utils::enum_to_value(texture.filter));
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter);
        CHECK_GL_ERRORS();
        if (texture.swizzle_mask != no_swizzle) {
            int32_t const swizzle_mask[] = {static_cast<int32_t>(texture.swizzle_mask) & 0xFFFF, static_cast<int32_t>(texture.swizzle_mask >> 16) & 0xFFFF,
                                            static_cast<int32_t>(texture.swizzle_mask >> 32) & 0xFFFF,
                                            static_cast<int32_t>(texture.swizzle_mask >> 48) & 0xFFFF};
            glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_RGBA, swizzle_mask);
        }
        CHECK_GL_ERRORS();
        opengl::generate_mipmap(GL_TEXTURE_2D); // TODO generate offline
        return texture_gl_handle;
    }

    static void compute_tangents(Vertex& vert1, Vertex& vert2, Vertex& vert3) {
        Vector3 const delta_pos1 = vert2.position - vert1.position;
        Vector3 const delta_pos2 = vert3.position - vert1.position;
        Vector2 const delta_uv1 = vert2.uv_coordinates - vert1.uv_coordinates;
        Vector2 const delta_uv2 = vert3.uv_coordinates - vert1.uv_coordinates;
        float const determinant = delta_uv1.x * delta_uv2.y - delta_uv1.y * delta_uv2.x;
        Vector3 const tangent = math::normalize((delta_uv2.y * delta_pos1 - delta_uv1.y * delta_pos2) / determinant);
        Vector3 const bitangent = math::normalize((delta_uv1.x * delta_pos2 - delta_uv2.x * delta_pos1) / determinant);

        vert1.tangent = vert2.tangent = vert3.tangent = tangent;
        vert1.bitangent = vert2.bitangent = vert3.bitangent = bitangent;
        //vert1.bitangent = vert2.bitangent = vert3.bitangent = Vector3::cross(vert1.normal, vert1.tangent);
    }

    static Mesh process_mesh(importers::Mesh const& imported_mesh) {
        anton_stl::Vector<Vertex> vertices(imported_mesh.vertices.size());
        anton_stl::Vector<uint32_t> indices;
        if (imported_mesh.texture_coordinates.size() != 0) {
            for (anton_stl::ssize_t i = 0; i < imported_mesh.vertices.size(); ++i) {
                vertices[i].position = imported_mesh.vertices[i];
                vertices[i].normal = imported_mesh.normals[i];
                vertices[i].uv_coordinates = Vector2(imported_mesh.texture_coordinates[i]);
            }
        } else {
            for (anton_stl::ssize_t i = 0; i < imported_mesh.vertices.size(); ++i) {
                vertices[i].position = imported_mesh.vertices[i];
                vertices[i].normal = imported_mesh.normals[i];
            }
        }

        for (importers::Face const& imported_face: imported_mesh.faces) {
            for (uint32_t index: imported_face.indices) { // TODO use vector's assign once I implement it correctly
                indices.push_back(index);
            }
        }

        for (anton_stl::ssize_t i = 0; i < indices.size(); i += 3) {
            compute_tangents(vertices[indices[i]], vertices[indices[i + 1]], vertices[indices[i + 2]]);
        }

        return {std::move(vertices), std::move(indices)};
    }

    anton_stl::Vector<Mesh> load_model(std::filesystem::path const& path) {
        // TODO will not compile in shipping build
        auto asset_path = utils::concat_paths(paths::assets_directory(), path);
        auto extension = asset_path.extension();
        anton_stl::Vector<Mesh> meshes;
        if (extension == ".obj") { // TODO Don't load directly from obj. Use a proprietary format
            auto file = utils::read_file_binary(asset_path);
            auto imported_meshes = importers::import_obj(file);
            for (auto& imported_mesh: imported_meshes) {
                flip_texture_coordinates(imported_mesh.texture_coordinates);
                meshes.push_back(process_mesh(imported_mesh));
            }
        } else {
            throw std::runtime_error("Unsupported file format");
        }
        return meshes;
    }
} // namespace anton_engine::assets
