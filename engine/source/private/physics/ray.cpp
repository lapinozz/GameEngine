#include <physics/ray.hpp>

namespace anton_engine {
    Ray screen_to_ray(Matrix4 inv_view, Matrix4 inv_projection, i32 screen_width, i32 screen_height, Vector2 point) {
        // Transform screen point to normalized -1..1 coordinates
        float const normalized_x = 2.0f * point.x / static_cast<float>(screen_width) - 1.0f;
        float const normalized_y = 2.0f * point.y / static_cast<float>(screen_height) - 1.0f;

        Vector4 const ray_start = Vector4(normalized_x, normalized_y, -1.0f, 1.0f);
        Vector4 const ray_end = Vector4(normalized_x, normalized_y, 0.0f, 1.0f);

        Vector4 const ray_start_hg = ray_start * inv_projection;
        Vector4 const ray_end_hg = ray_end * inv_projection;

        Vector3 ray_start_homogenized = Vector3(ray_start_hg);
        Vector3 ray_end_homogenized = Vector3(ray_end_hg);

        if (ray_start_hg.w != 0.0f) {
            ray_start_homogenized /= ray_start_hg.w;
        }
        if (ray_end_hg.w != 0.0f) {
            ray_end_homogenized /= ray_end_hg.w;
        }

        Vector3 ray_direction_view_space = ray_end_homogenized - ray_start_homogenized;
        ray_direction_view_space = math::normalize(ray_direction_view_space);

        Vector3 ray_start_world_space = Vector3(Vector4(ray_start_homogenized, 1.0f) * inv_view);
        Vector3 ray_direction_world_space = Vector3(Vector4(ray_direction_view_space, 0.0f) * inv_view);
        ray_direction_world_space = math::normalize(ray_direction_world_space);

        return {ray_start_world_space, ray_direction_world_space};
    }

    Ray screen_to_ray(Matrix4 inv_view_projection_matrix, i32 screen_width, i32 screen_height, Vector2 point) {
        // Transform screen point to normalized -1..1 coordinates
        float const normalized_x = 2.0f * point.x / static_cast<float>(screen_width) - 1.0f;
        float const normalized_y = 2.0f * point.y / static_cast<float>(screen_height) - 1.0f;

        // Since z=1 is far and z=-1 is near in NDC, we use -1 for the start and 0 for the end to get better precision.
        Vector4 const ray_start = Vector4(normalized_x, normalized_y, -1.0f, 1.0f);
        Vector4 const ray_end = Vector4(normalized_x, normalized_y, 0.0f, 1.0f);

        Vector4 const ray_start_world_space = ray_start * inv_view_projection_matrix;
        Vector4 const ray_end_world_space = ray_end * inv_view_projection_matrix;

        Vector3 ray_start_homogenized = Vector3(ray_start_world_space);
        Vector3 ray_end_homogenized = Vector3(ray_end_world_space);

        if (ray_start_world_space.w != 0.0f) {
            ray_start_homogenized /= ray_start_world_space.w;
        }
        if (ray_end_world_space.w != 0.0f) {
            ray_end_homogenized /= ray_end_world_space.w;
        }

        Vector3 ray_direction = ray_end_homogenized - ray_start_homogenized;
        ray_direction = math::normalize(ray_direction);

        return {ray_start_homogenized, ray_direction};
    }
} // namespace anton_engine
