#ifndef SCRIPTS_DEBUG_HOTKEYS_HPP_INCLUDE
#define SCRIPTS_DEBUG_HOTKEYS_HPP_INCLUDE

#include <class_macros.hpp>
#include <serialization/serialization.hpp>

namespace anton_engine {
    class COMPONENT Debug_Hotkeys {
    public:
        bool cursor_captured = false;

        static void update(Debug_Hotkeys&);
    };
} // namespace anton_engine

ANTON_DEFAULT_SERIALIZABLE(anton_engine::Debug_Hotkeys);
ANTON_DEFAULT_DESERIALIZABLE(anton_engine::Debug_Hotkeys);

#endif // !SCRIPTS_DEBUG_HOTKEYS_HPP_INCLUDE
