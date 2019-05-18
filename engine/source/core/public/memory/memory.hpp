#ifndef CORE_MEMORY_MEMORY_HPP_INCLUDE
#define CORE_MEMORY_MEMORY_HPP_INCLUDE

#include "iterators.hpp"
#include <type_traits>

template <typename T>
void destruct(T* elem) {
    elem->~T();
}

template <typename Forward_Iterator>
void destruct(Forward_Iterator first, Forward_Iterator last) {
    using value_type = typename iterators::iterator_traits<Forward_Iterator>::value_type;
    if constexpr (!std::is_trivially_destructible_v<value_type>) {
        for (; first != last; ++first) {
            first->~value_type();
        }
    }
}

template <typename Forward_Iterator, typename Count>
void destruct_n(Forward_Iterator first, Count n) {
    using value_type = typename iterators::iterator_traits<Forward_Iterator>::value_type;
    if constexpr (!std::is_trivially_destructible_v<value_type>) {
        for (; n > 0; --n, ++first) {
            first->~value_type();
        }
    }
}

template <typename Input_Iterator, typename Forward_Iterator>
Forward_Iterator uninitialized_copy(Input_Iterator first, Input_Iterator last, Forward_Iterator dest) {
    using value_type = typename iterators::iterator_traits<Forward_Iterator>::value_type;
    Forward_Iterator dest_copy = dest;
    try {
        for (; first != last; ++first, ++dest) {
            ::new (dest) value_type(*first);
        }
    } catch (...) {
        destruct(dest_copy, dest);
        throw;
    }
    return dest;
}

template <typename Input_Iterator, typename Count, typename Forward_Iterator>
Forward_Iterator uninitialized_copy_n(Input_Iterator first, Count n, Forward_Iterator dest) {
    using value_type = typename iterators::iterator_traits<Forward_Iterator>::value_type;
    Forward_Iterator dest_copy = dest;
    try {
        for (; n > 0; --n, ++first, ++dest) {
            ::new (dest) value_type(*first);
        }
    } catch (...) {
        destruct(dest_copy, dest);
        throw;
    }
    return dest;
}

template <typename Input_Iterator, typename Forward_Iterator>
Forward_Iterator uninitialized_move(Input_Iterator first, Input_Iterator last, Forward_Iterator dest) {
    using value_type = typename iterators::iterator_traits<Forward_Iterator>::value_type;
    Forward_Iterator dest_copy = dest;
    try {
        for (; first != last; ++first, ++dest) {
            ::new (dest) value_type(std::move(*first));
        }
    } catch (...) {
        destruct(dest_copy, dest);
        throw;
    }
    return dest;
}

template <typename Input_Iterator, typename Count, typename Forward_Iterator>
Forward_Iterator uninitialized_move_n(Input_Iterator first, Count n, Forward_Iterator dest) {
    using value_type = typename iterators::iterator_traits<Forward_Iterator>::value_type;
    Forward_Iterator dest_copy = dest;
    try {
        for (; n > 0; --n, ++first, ++dest) {
            ::new (dest) value_type(std::move(*first));
        }
    } catch (...) {
        destruct(dest_copy, dest);
        throw;
    }
    return dest;
}

template <typename Forward_Iterator>
void uninitialized_default_construct(Forward_Iterator first, Forward_Iterator last) {
    using value_type = typename iterators::iterator_traits<Forward_Iterator>::value_type;
    Forward_Iterator first_copy = first;
    try {
        for (; first != last; ++first) {
            ::new (first) value_type();
        }
    } catch (...) {
        destruct(first_copy, first);
        throw;
    }
}

template <typename Forward_Iterator, typename Count>
void uninitialized_default_construct_n(Forward_Iterator first, Count n) {
    using value_type = typename iterators::iterator_traits<Forward_Iterator>::value_type;
    Forward_Iterator first_copy = first;
    try {
        for (; n > 0; --n, ++first) {
            ::new (first) value_type();
        }
    } catch (...) {
        destruct(first_copy, first);
        throw;
    }
}

template <typename Forward_Iterator, typename T>
void uninitialized_fill(Forward_Iterator first, Forward_Iterator last, T const& val) {
    using value_type = typename iterators::iterator_traits<Forward_Iterator>::value_type;
    Forward_Iterator first_copy = first;
    try {
        for (; first != last; ++first) {
            ::new (first) value_type(val);
        }
    } catch (...) {
        destruct(first_copy, first);
        throw;
    }
}

template <typename Forward_Iterator, typename Count, typename T>
void uninitialized_fill_n(Forward_Iterator first, Count n, T const& val) {
    using value_type = typename iterators::iterator_traits<Forward_Iterator>::value_type;
    Forward_Iterator first_copy = first;
    try {
        for (; n > 0; --n, ++first) {
            ::new (first) value_type(val);
        }
    } catch (...) {
        destruct(first_copy, first);
        throw;
    }
}

#endif // !CORE_MEMORY_MEMORY_HPP_INCLUDE
