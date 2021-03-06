#version 450 core

in Frag_Data {
    mat3 tbn;
    vec3 normal;
    vec2 tex_coords;
    flat uint draw_id;
} fs_in;

struct Texture {
    uint index;
    float layer;
};

struct Material {
    Texture diffuse;
    Texture specular;
    Texture normal_map;
    float shininess;
};

layout(std140, binding = 2) readonly buffer Materials {
    Material materials[];
};

layout(binding = 0) uniform sampler2DArray array_textures[16];

layout(location = 0) out vec3 gbuf_normal;
layout(location = 1) out vec4 gbuf_albedo_spec;

vec3 get_surface_normal(sampler2DArray normal_map, vec3 tex_pos);
vec3 color_to_normal(vec3 c);

void main() {
    Material material = materials[fs_in.draw_id];
    vec3 surface_normal = get_surface_normal(array_textures[material.normal_map.index], vec3(fs_in.tex_coords, material.normal_map.layer));
    // vec3 surface_normal = fs_in.normal;
    vec4 tex_color = texture(array_textures[material.diffuse.index], vec3(fs_in.tex_coords, material.diffuse.layer));
    vec4 specular_tex_color = texture(array_textures[material.specular.index], vec3(fs_in.tex_coords, material.specular.layer));

    gbuf_normal = surface_normal;
    gbuf_albedo_spec = vec4(tex_color.rgb, specular_tex_color.r);
}

vec3 color_to_normal(vec3 c) {
    return c * 2.0 - 1.0;
}

vec3 get_surface_normal(sampler2DArray normal_map, vec3 tex_pos) {
    vec3 tex_normal = textureLod(normal_map, tex_pos, 0.0).rgb;
    vec3 normal = color_to_normal(tex_normal);
    return normalize(fs_in.tbn * normal);
}
