#ifndef ENGINE_ENTITY_HPP_INCLUDE
#define ENGINE_ENTITY_HPP_INCLUDE

#include <cstdint>

class Entity {
public:
    using id_type = uint64_t;
    id_type id;
};

bool operator==(Entity const&, Entity const&);
bool operator!=(Entity const&, Entity const&);

#endif // !ENGINE_ENTITY_HPP_INCLUDE