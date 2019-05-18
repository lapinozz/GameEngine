#include "components/camera.hpp"
#include "components/transform.hpp"
#include "engine.hpp"
#include "math/transform.hpp"

Vector3 get_camera_top(Transform& transform) {
    // TODO return global instead of local probably
    Vector4 top = Vector4(0, 1, 0, 0) * math::transform::rotate(transform.local_rotation);
    return {top.x, top.y, top.z};
}

Vector3 get_camera_front(Transform& transform) {
    // TODO return global instead of local probably
    Vector4 front = Vector4(0, 0, -1, 0) * math::transform::rotate(transform.local_rotation);
    return {front.x, front.y, front.z};
}

Matrix4 get_camera_view_matrix(Transform& transform) {
    return math::transform::look_at(transform.local_position, transform.local_position + get_camera_front(transform), get_camera_top(transform));
}

Matrix4 get_camera_projection_matrix(Camera& camera, uint32_t width, uint32_t height) {
    float aspect_ratio = static_cast<float>(width) / static_cast<float>(height);
    return math::transform::perspective(camera.fov, aspect_ratio, camera.near_plane, camera.far_plane);

    // Ortographic camera stuff
    // return math::transform::orthographic(-size * aspect_ratio, size * aspect_ratio, -size, size, near_plane, far_plane);
}

//Vector3 screen_to_world_point(Camera camera, Transform transform, uint32_t window_width, uint32_t window_height, Vector2 point) {}