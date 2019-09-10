#ifndef EDITOR_ASSET_IMPORTER_POSTPROCESS_HPP_INCLUDE
#define EDITOR_ASSET_IMPORTER_POSTPROCESS_HPP_INCLUDE

#include <anton_stl/vector.hpp>
#include <math/vector3.hpp>

namespace anton_engine {
    inline void flip_texture_coordinates(anton_stl::Vector<Vector3>& texture_coordinates) {
        for (Vector3& coords: texture_coordinates) {
            coords.y = 1.0f - coords.y;
        }
    }
} // namespace anton_engine
#endif // !EDITOR_ASSET_IMPORTER_POSTPROCESS_HPP_INCLUDE
