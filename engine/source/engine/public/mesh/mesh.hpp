#ifndef ENGINE_MESH_HPP_INCLUDE
#define ENGINE_MESH_HPP_INCLUDE

#include "math/vector2.hpp"
#include "math/vector3.hpp"
#include "object.hpp"
#include <string>
#include <vector>

enum class Texture_Type {
    specular,
    diffuse,
};

struct Vertex {
    Vector3 position;
    Vector3 normal;
    Vector2 uv_coordinates;

    Vertex() = default;
    Vertex(Vector3, Vector3, Vector2);
};

struct Texture {
    std::string name;
    Texture_Type type;
    uint32_t id;
};

class Shader;

class Mesh : public Object {
public:
    Mesh();
    Mesh(std::vector<Vertex> const& vertices, std::vector<uint32_t> const& indices, std::vector<Texture> const& textures);
    Mesh(std::vector<Vertex>&& vertices, std::vector<uint32_t>&& indices, std::vector<Texture>&& textures);
    Mesh(Mesh&&) noexcept;
    Mesh& operator=(Mesh&&) noexcept;
    ~Mesh();

    Mesh(Mesh const&) = delete;
    Mesh& operator=(Mesh const&) = delete;

    void draw(Shader&);
    void draw_instanced(Shader&, uint32_t count);
    void bind();
    void unbind();

private:
    void prepare_mesh();

public:
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
    std::vector<Texture> textures;

private:
    uint32_t vao = 0;
    uint32_t vbo = 0;
    uint32_t ebo = 0;
};

#endif // !ENGINE_MESH_HPP_INCLUDE