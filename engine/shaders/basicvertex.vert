#version 450 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 in_normal;
layout(location = 2) in vec3 in_tangent;
layout(location = 3) in vec3 in_bitangent;
layout(location = 4) in vec2 tex_coordinates;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
uniform mat4 light_space_transform;

out Frag_Data {
    mat3 tbn;
    vec3 fragment_position;
    vec3 light_space_frag_position;
    vec3 normal;
    vec2 tex_coords;
} vs_out;

void main() {
    mat3 model_reduced = mat3(model);
    vec3 normal = normalize(transpose(inverse(model_reduced)) * in_normal);
    vec3 tangent = normalize(model_reduced * in_tangent);
    vec3 bitangent = normalize(model_reduced * in_bitangent);

    gl_Position = projection * view * model * vec4(pos, 1.0);
    vs_out.fragment_position = vec3(model * vec4(pos, 1.0));
    vs_out.normal = normal;
    vs_out.tex_coords = tex_coordinates;
    vs_out.tbn = mat3(tangent, bitangent, normal);
    vs_out.light_space_frag_position = vec3(light_space_transform * vec4(vs_out.fragment_position, 1.0));
}
