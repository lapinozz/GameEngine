#ifndef ENGINE_COMPONENTS_CAMERA_HPP_INCLUDE
#define ENGINE_COMPONENTS_CAMERA_HPP_INCLUDE

#include <class_macros.hpp>
#include <components/transform.hpp>
#include <math/matrix4.hpp>
#include <math/vector2.hpp>
#include <math/vector3.hpp>
#include <serialization/serialization.hpp>

#include <cstdint>

namespace anton_engine {
    class COMPONENT Camera {
    public:
        // Size of the camera in ortographic projection
        // float size = 5;
        // Field of view in perspective projection
        float fov = 70;
        float near_plane = 0.3f;
        float far_plane = 1000.0f;
        bool active = true; // Temporarily make active by default
    };

    Vector3 get_camera_top(Transform&);
    Vector3 get_camera_front(Transform&);
    Matrix4 get_camera_view_matrix(Transform&);
    Matrix4 get_camera_projection_matrix(Camera&, int32_t viewport_width, int32_t viewport_height);
} // namespace anton_engine

ANTON_DEFAULT_SERIALIZABLE(anton_engine::Camera);
ANTON_DEFAULT_DESERIALIZABLE(anton_engine::Camera);

#endif // !ENGINE_COMPONENTS_CAMERA_HPP_INCLUDE
