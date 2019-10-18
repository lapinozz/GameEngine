#ifndef CORE_ANTON_STL_CONFIG_HPP_INCLUDE
#define CORE_ANTON_STL_CONFIG_HPP_INCLUDE

#include <anton_int.hpp>

#ifndef ANTON_NOEXCEPT
#    define ANTON_NOEXCEPT
#endif

namespace anton_engine::anton_stl {
    using size_t = u64;
    using ptrdiff_t = i64;
    // signed counterpart of anton_stl::size_t
    using ssize_t = i64;

    // Reserve_Tag
    // Allows us to create constructors that allocate certain capacity, but do not initialize/resize
    struct Reserve_Tag {
        explicit Reserve_Tag() = default; // Explicit constructor so that it may not be constructed via {}
    };
    constexpr Reserve_Tag reserve;

    // Variadic_Construct_Tag
    // Allows us to create variadic constructors
    struct Variadic_Construct_Tag {
        explicit Variadic_Construct_Tag() = default; // Explicit constructors so that it may not be constructed via {}
    };
    constexpr Variadic_Construct_Tag variadic_construct;
} // namespace anton_engine::anton_stl

// Convinience type aliases

using anton_size_t = anton_engine::anton_stl::size_t;
using anton_ptrdiff_t = anton_engine::anton_stl::ptrdiff_t;
using anton_ssize_t = anton_engine::anton_stl::ssize_t;

#endif // !CORE_ANTON_STL_CONFIG_HPP_INCLUDE
