#version 450 core

in vec3 normal;
in vec3 fragment_position;

uniform vec3 light_color;
uniform vec3 object_color;
uniform vec3 light_position;
uniform vec3 view_position;

out vec4 frag_color;

void main() {
    float ambient_strength = 0.1;
    vec3 ambient = ambient_strength * light_color;

    vec3 light_direction = normalize(light_position - fragment_position);
    float diffuse_strength = max(dot(normal, light_direction), 0.0);
    vec3 diffuse = diffuse_strength * light_color;

    float specular_strength = 0.5;
    vec3 view_direction = normalize(view_position - fragment_position);
    vec3 reflect_direction = reflect(-light_direction, normal);
    float specular_component = pow(max(dot(view_direction, reflect_direction), 0.0), 32);
    vec3 specular = specular_strength * specular_component * light_color;

    frag_color = vec4((ambient + diffuse + specular) * object_color, 1.0);
}