#ifndef CORE_ATL_UTILITY_COMMON_HPP_INCLUDE
#define CORE_ATL_UTILITY_COMMON_HPP_INCLUDE

#include <core/types.hpp>
#include <core/atl/type_traits.hpp>

namespace anton_engine::atl {
    template <typename T>
    inline constexpr void swap(T& a, T& b) {
        T tmp(atl::move(a));
        a = atl::move(b);
        b = atl::move(tmp);
    }

    template <typename T, typename U, typename = void>
    struct Is_Swappable_With: False_Type {};

    // Note: swap left unprefixed to allow ADL of user-defined swap specializations
    template <typename T, typename U>
    struct Is_Swappable_With<T, U, void_trait<decltype(swap(declval<U&>(), declval<T&>())), decltype(swap(declval<T&>(), declval<U&>()))>>: True_Type {};

    template <typename T, typename U>
    inline constexpr bool is_swappable_with = Is_Swappable_With<T, U>::value;

    template <typename T>
    struct Is_Swappable: Is_Swappable_With<T, T> {};

    template <typename T>
    inline constexpr bool is_swappable = Is_Swappable<T>::value;

    template <typename>
    struct Tuple_Size;

    template <usize, typename>
    struct Tuple_Element;

    template <usize I, typename T>
    using tuple_element = typename Tuple_Element<I, T>::type;
} // namespace anton_engine::atl

// We provide std::tuple_size and std::tuple_element to enable structured bindings on certain types
// so we forward declare those types so that we do not have to deal with errors or std headers.
namespace std {
    template<typename>
    struct tuple_size;

    template<unsigned long long, typename>
    struct tuple_element;
}

#endif // !CORE_ATL_UTILITY_COMMON_HPP_INCLUDE
