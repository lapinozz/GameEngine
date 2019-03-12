#include "mesh/plane.hpp"

Plane::Plane()
    : Mesh({Vertex({-1, 1, 0}, {0, 0, 1}, {1, 0, 0}, {0, 1, 0}, {0, 1}), Vertex({-1, -1, 0}, {0, 0, 1}, {1, 0, 0}, {0, 1, 0}, {0, 0}),
            Vertex({1, -1, 0}, {0, 0, 1}, {1, 0, 0}, {0, 1, 0}, {1, 0}), Vertex({-1, 1, 0}, {0, 0, 1}, {1, 0, 0}, {0, 1, 0}, {0, 1}),
            Vertex({1, -1, 0}, {0, 0, 1}, {1, 0, 0}, {0, 1, 0}, {1, 0}), Vertex({1, 1, 0}, {0, 0, 1}, {1, 0, 0}, {0, 1, 0}, {1, 1})},
           {0, 1, 2, 3, 4, 5}, {}) {}