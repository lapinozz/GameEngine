#include "shader.hpp"
#include <iostream>

Shader_file::Shader_file(Shader_type type, std::string const& source) : type(type), shader(0) {
    create();
    set_source(source);
    compile();
}

Shader_file::Shader_file(Shader_file&& shader) noexcept : shader(shader.shader), type(shader.type) {
    shader.shader = 0;
}

Shader_file& Shader_file::operator=(Shader_file&& shader) noexcept {
    this->shader = shader.shader;
    shader.shader = 0;
    return *this;
}

Shader_file::~Shader_file() {
    if (shader != 0) {
        glDeleteShader(shader);
    }
}

void Shader_file::create() {
    if (type == Shader_type::vertex) {
        shader = glCreateShader(GL_VERTEX_SHADER);
    } else if (type == Shader_type::fragment) {
        shader = glCreateShader(GL_FRAGMENT_SHADER);
    } else if (type == Shader_type::geometry) {
        shader = glCreateShader(GL_GEOMETRY_SHADER);
    } else if (type == Shader_type::compute) {
        shader = glCreateShader(GL_COMPUTE_SHADER);
    } else if (type == Shader_type::tessellation_control) {
        shader = glCreateShader(GL_TESS_CONTROL_SHADER);
    } else {
        shader = glCreateShader(GL_TESS_EVALUATION_SHADER);
    }

    if (shader == 0) {
        throw Shader_not_created("");
    }
}

void Shader_file::set_source(std::string const& source) {
    const char* src = source.c_str();
    glShaderSource(shader, 1, &src, NULL);
}

void Shader_file::compile() {
    glCompileShader(shader);

    GLint compilation_status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compilation_status);
    if (compilation_status == GL_FALSE) {
        GLint log_length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_length);
        std::vector<GLchar> log(log_length);
        glGetShaderInfoLog(shader, log_length, &log_length, &log[0]);
        std::string log_string(log.begin(), log.end());
        throw Shader_compilation_failed(std::move(log_string));
    }
}