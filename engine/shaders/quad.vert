#version 450 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 in_normal;
layout(location = 4) in vec2 tex_coordinates;

out vec2 texture_coordinates;

void main() {
    gl_Position = vec4(pos, 1.0);
    texture_coordinates = tex_coordinates;
}
