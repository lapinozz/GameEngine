#include "components/camera.hpp"
#include "components/transform.hpp"
#include "engine.hpp"
#include "math/transform.hpp"
#include "window.hpp"
#include "components/component_system.hpp"

Camera::Camera(Entity const& entity) : Base_Component(entity) {}

Camera::~Camera() {}

void Camera::set_projection(Projection proj) {
    projection = proj;
}

Vector3 Camera::get_front() {
    Transform& transform = get_component<Transform>(get_entity());
    Vector4 front = Vector4(0, 0, -1, 0) * transform::rotate(transform.local_rotation);
    return {front.x, front.y, front.z};
}

Matrix4 Camera::get_view_matrix() {
    Transform& transform = get_component<Transform>(get_entity());
    return transform::look_at(transform.local_position, transform.local_position + get_front(), Vector3::up);
}

Matrix4 Camera::get_projection_matrix() {
    Window& window = Engine::get_window();
    float aspect_ratio = static_cast<float>(window.width()) / static_cast<float>(window.height());
    if (projection == Projection::perspective) {
        return transform::perspective(fov, aspect_ratio, near_plane, far_plane);
    } else {
        return transform::orthographic(-size * aspect_ratio, size * aspect_ratio, -size, size, near_plane, far_plane);
    }
}

void Camera::activate() {
    active = true;
}

void Camera::deactivate() {
    active = false;
}

bool Camera::is_active() {
    return active;
}
