#ifndef CORE_ATL_ALGORITHM_HPP_INCLUDE
#define CORE_ATL_ALGORITHM_HPP_INCLUDE

#include <core/exception.hpp>

namespace anton_engine::atl {
    // iota
    // Fill range [first, last[ with consecutive values starting at value.
    //
    template <typename Forward_Iterator, typename T>
    void iota(Forward_Iterator first, Forward_Iterator last, T value) {
        for (; first != last; ++first, ++value) {
            *first = value;
        }
    }

    // at
    // Performs bounds checking and accesses an element at index in container.
    //
    // Returns: A reference to an element at index.
    //
    // Throws: Exception if index is out of bounds.
    //
    template <typename T>
    [[nodiscard]] inline typename T::reference at(T& container, typename T::size_type index) {
        if (index >= container.size() || index < typename T::size_type(0)) {
            throw Exception(u8"Index out of range");
        }
        return container[index];
    }

    // at
    // Performs bounds checking and accesses an element at index in container.
    //
    // Returns: A reference to a const element at index.
    //
    // Throws: Exception if index is out of bounds.
    //
    template <typename T>
    [[nodiscard]] inline typename T::const_reference at(T const& container, typename T::size_type index) {
        if (index >= container.size() || index < typename T::size_type(0)) {
            throw Exception(u8"Index out of range");
        }
        return container[index];
    }

    // find
    // Linearily searches the range [first, last[.
    //
    // Returns: The iterator to the first element in the range [first, last[ that satisfies
    // the condition *iterator == value or last if no such iterator is found.
    //
    // Complexity: At most 'last - first' comparisons.
    //
    template <typename Input_Iterator, typename T>
    [[nodiscard]] inline Input_Iterator find(Input_Iterator first, Input_Iterator last, T const& value) {
        while (first != last && *first != value) {
            ++first;
        }
        return first;
    }

    // find_if
    // Linearily searches the range [first, last[.
    //
    // Returns: The iterator to the first element in the range [first, last[ that satisfies
    // the condition predicate(*iterator) == true or last if no such iterator is found.
    //
    // Complexity: At most 'last - first' applications of the predicate.
    //
    template <typename Input_Iterator, typename Predicate>
    [[nodiscard]] inline Input_Iterator find_if(Input_Iterator first, Input_Iterator last, Predicate predicate) {
        while (first != last && !predicate(*first)) {
            ++first;
        }
        return first;
    }

    // find_if_not
    // find_if_not works the same as find_if except it searches for an element for which the predicate returns false.
    //
    template <typename Input_Iterator, typename Predicate>
    [[nodiscard]] inline Input_Iterator find_if_not(Input_Iterator first, Input_Iterator last, Predicate predicate) {
        while (first != last && predicate(*first)) {
            ++first;
        }
        return first;
    }

    template <typename Input_Iterator, typename Predicate>
    [[nodiscard]] inline bool any_of(Input_Iterator first, Input_Iterator last, Predicate predicate) {
        for (; first != last; ++first) {
            if (predicate(*first)) {
                return true;
            }
        }

        return false;
    }
} // namespace anton_engine::atl

#endif // !CORE_ATL_ALGORITHM_HPP_INCLUDE
