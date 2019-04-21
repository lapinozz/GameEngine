#include "math/math.hpp"
#include "memory/memory.hpp"
#include "memory/stack_allocate.hpp"

namespace containers {
    template <typename T, typename Allocator>
    Vector<T, Allocator>::Vector() {
        storage = allocator.allocate(_capacity);
    }

    template <typename T, typename Allocator>
    Vector<T, Allocator>::Vector(size_type cap) : _capacity(cap) {
        storage = allocator.allocate(cap);
    }

    template <typename T, typename Allocator>
    Vector<T, Allocator>::Vector(Vector const& v) : _capacity(v._capacity), allocator(v.allocator) {
        storage = allocator.allocate(_capacity);
        try {
            uninitialized_copy_n(v.storage, v._size, storage);
            _size = v._size;
        } catch (...) {
            allocator.deallocate(storage, _capacity);
            throw;
        }
    }

    template <typename T, typename Allocator>
    Vector<T, Allocator>::Vector(Vector&& v) noexcept : storage(v.storage), allocator(std::move(v.allocator)), _capacity(v._capacity), _size(v._size) {
        v.storage = nullptr;
        v._capacity = 0;
        v._size = 0;
    }

    template <typename T, typename Allocator>
    Vector<T, Allocator>& Vector<T, Allocator>::operator=(Vector const& v) {
        allocator = v.allocator;
        _capacity = v._capacity;
        storage = allocator.allocate(_capacity);
        try {
            uninitialized_copy_n(v.storage, v._size, storage);
            _size = v._size;
        } catch (...) {
            allocator.deallocate(storage, _capacity);
            throw;
        }
        return *this;
    }

    template <typename T, typename Allocator>
    Vector<T, Allocator>& Vector<T, Allocator>::operator=(Vector&& v) noexcept {
        std::swap(storage, v.storage);
        std::swap(allocator, v.allocator);
        std::swap(_capacity, v._capacity);
        std::swap(_size, v._size);
        return *this;
    }

    template <typename T, typename Allocator>
    Vector<T, Allocator>::~Vector() {
        if (storage != nullptr) {
            destruct_n(storage, _size);
            allocator.deallocate(storage, _capacity);
        }
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::reference Vector<T, Allocator>::at(size_type index) {
        if (index >= _size) {
            throw std::out_of_range("index out of range");
        }
        return at_unchecked(index);
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::const_reference Vector<T, Allocator>::at(size_type index) const {
        if (index >= _size) {
            throw std::out_of_range("index out of range");
        }
        return at_unchecked(index);
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::reference Vector<T, Allocator>::at_unchecked(size_type index) {
        T* object = get_ptr(index);
        return *object;
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::const_reference Vector<T, Allocator>::at_unchecked(size_type index) const {
        T* object = get_ptr(index);
        return *object;
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::reference Vector<T, Allocator>::operator[](size_type index) {
        return at_unchecked(index);
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::const_reference Vector<T, Allocator>::operator[](size_type index) const {
        return at_unchecked(index);
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::reference Vector<T, Allocator>::front() {
        return at_unchecked(0);
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::const_reference Vector<T, Allocator>::front() const {
        return at_unchecked(0);
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::reference Vector<T, Allocator>::back() {
        return at_unchecked(_size - 1);
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::const_reference Vector<T, Allocator>::back() const {
        return at_unchecked(_size - 1);
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::pointer Vector<T, Allocator>::data() {
        return get_ptr();
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::const_pointer Vector<T, Allocator>::data() const {
        return get_ptr();
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::iterator Vector<T, Allocator>::begin() {
        return iterator(get_ptr());
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::iterator Vector<T, Allocator>::end() {
        return iterator(get_ptr(_size));
    }
    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::const_iterator Vector<T, Allocator>::begin() const {
        return const_iterator(get_ptr());
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::const_iterator Vector<T, Allocator>::end() const {
        return const_iterator(get_ptr(_size));
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::const_iterator Vector<T, Allocator>::cbegin() const {
        return const_iterator(get_ptr());
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::const_iterator Vector<T, Allocator>::cend() const {
        return const_iterator(get_ptr(_size));
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::reverse_iterator Vector<T, Allocator>::rbegin() {
        return reverse_iterator(end());
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::reverse_iterator Vector<T, Allocator>::rend() {
        return reverse_iterator(begin());
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::const_reverse_iterator Vector<T, Allocator>::crbegin() const {
        return const_reverse_iterator(cend());
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::const_reverse_iterator Vector<T, Allocator>::crend() const {
        return const_reverse_iterator(cbegin());
    }

    template <typename T, typename Allocator>
    bool Vector<T, Allocator>::empty() const {
        return _size == 0;
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::size_type Vector<T, Allocator>::size() const {
        return _size;
    }

    template <typename T, typename Allocator>
    typename Vector<T, Allocator>::size_type Vector<T, Allocator>::capacity() const {
        return _capacity;
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::resize(size_type n, value_type const& value) {
        // TODO not exception safe (I guess??)
        if (n > _capacity) {
            grow(n); // TODO apply growing policy here?
        }

        if (n > _size) {
            uninitialized_fill(get_ptr(_size), get_ptr(n), value);
        } else {
            destruct(get_ptr(n), get_ptr(_size));
        }
        _size = n;
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::resize(size_type n) {
        // TODO not exception safe (I guess??)
        if (n > _capacity) {
            grow(n); // TODO apply growing policy here?
        }

        if (n > _size) {
            uninitialized_default_construct(get_ptr(_size), get_ptr(n));
        } else {
            destruct(get_ptr(n), get_ptr(_size));
        }
        _size = n;
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::reserve(size_type n) {
        if (n > _capacity) {
            grow(n);
        }
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::set_capacity(size_type n) {
        if (n > _capacity) { // Expected to happen more often
            grow(n);
        } else if (n < _capacity) {
            shrink(n);
        }
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::shrink_to_fit() {
        if (_size < _capacity) {
            shrink(_size);
        }
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::push_back(value_type const& val) {
        check_size();
        T* elem_ptr = get_ptr(_size);
        attempt_construct(elem_ptr, val);
        ++_size;
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::push_back(value_type&& val) {
        check_size();
        T* elem_ptr = get_ptr(_size);
        attempt_construct(elem_ptr, std::move(val));
        ++_size;
    }

    template <typename T, typename Allocator>
    template <typename... CtorArgs>
    typename Vector<T, Allocator>::reference Vector<T, Allocator>::emplace_back(CtorArgs&&... args) {
        check_size();
        T* elem_ptr = get_ptr(_size);
        attempt_construct(elem_ptr, std::forward<CtorArgs>(args)...);
        ++_size;
        return *elem_ptr;
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::erase_unsorted(size_type index) {
        if (index >= _size) {
            throw std::out_of_range("index out of range");
        }

        erase_unsorted_unchecked(index);
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::erase_unsorted_unchecked(size_type index) {
        T* elem_ptr = get_ptr(index);
        T* last_elem_ptr = get_ptr(_size - 1);
        *elem_ptr = std::move(*last_elem_ptr);
        destruct(last_elem_ptr);
        --_size;
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::clear() {
        destruct(get_ptr(), get_ptr(_size));
        _size = 0;
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::attempt_copy(T* from, T* to) {
        ::new (to) T(*from);
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::attempt_move(T* from, T* to) {
        ::new (to) T(std::move(*from));
    }

    template <typename T, typename Allocator>
    template <typename... Ctor_Args>
    void Vector<T, Allocator>::attempt_construct(T* in, Ctor_Args&&... args) {
        ::new (in) T(std::forward<Ctor_Args>(args)...);
    }

    template <typename T, typename Allocator>
    T* Vector<T, Allocator>::get_ptr(size_type index) const {
        return storage + index;
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::move_contents(T* const& from, T* const& to, size_type number_of_elements_to_copy) {
        // TODO if is not nothrow movable and is not copyable, use move constructor
        if constexpr (std::is_nothrow_move_constructible_v<T> /* || !std::is_copy_constructible_v<T> */) {
            uninitialized_move_n(from, number_of_elements_to_copy, to);
        } else {
            uninitialized_copy_n(from, number_of_elements_to_copy, to);
        }
    }

    // TODO remove? is essentially shrink, but with less functionality
    template <typename T, typename Allocator>
    void Vector<T, Allocator>::grow(size_type new_capacity) {
        // Assumes new_capacity >= _capacity
        T* new_storage = allocator.allocate(new_capacity);
        try {
            move_contents(storage, new_storage, _size);
        } catch (...) {
            allocator.deallocate(new_storage, _capacity);
            throw;
        }
        std::swap(storage, new_storage);
        destruct_n(new_storage, _size);
        allocator.deallocate(new_storage, _capacity);
        _capacity = new_capacity;
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::shrink(size_type new_capacity) {
        T* new_storage = allocator.allocate(new_capacity);
        size_type min_cap_size = math::min(new_capacity, _size);
        try {
            move_contents(storage, new_storage, min_cap_size);
        } catch (...) {
            allocator.deallocate(new_storage, new_capacity);
            throw;
        }
        std::swap(storage, new_storage);
        destruct_n(new_storage, _size);
        _capacity = new_capacity;
        _size = min_cap_size;
    }

    template <typename T, typename Allocator>
    void Vector<T, Allocator>::check_size() {
        if (_size == _capacity) {
            size_type new_capacity = _capacity * 2;
            grow(new_capacity);
        }
    }
} // namespace containers

namespace serialization {
    template <typename T, typename Allocator>
    void serialize(containers::Vector<T, Allocator> const& vec, std::ofstream& out) {
        using size_type = typename containers::Vector<T, Allocator>::size_type;
        size_type capacity = vec.capacity(), size = vec.size();
        serialization::detail::write(capacity, out);
        serialization::detail::write(size, out);
        for (T const& elem : vec) {
            serialization::serialize(elem, out);
        }
    }

    template <typename T, typename Allocator>
    void deserialize(containers::Vector<T, Allocator>& vec, std::ifstream& in) {
        using size_type = typename containers::Vector<T, Allocator>::size_type;
        size_type capacity, size;
        serialization::detail::read(capacity, in);
        serialization::detail::read(size, in);
        vec.clear();
        vec.set_capacity(capacity);
        if constexpr (serialization::is_in_place_deserializable_v<T>) {
            if constexpr (std::is_trivially_default_constructible_v<T>) {
                vec.resize(size);
                try {
                    for (T& elem : vec) {
                        serialization::deserialize(elem, in);
                    }
                } catch (...) {
                    // TODO move stream backward to maintain weak guarantee
                    destruct_n(vec.get_ptr(), size);
                    throw;
                }
            } else {
                size_type n = size;
                try {
                    for (; n > 0; --n) {
                        Stack_Allocate<T> elem;
                        vec.push_back(std::move(elem.reference()));
                        serialization::deserialize(vec.back(), in);
                    }
                    vec._size = size;
                } catch (...) {
                    // TODO move stream backward to maintain weak guarantee
                    destruct_n(vec.get_ptr(), size - n);
                    throw;
                }
            }
        } else {
            T* first = vec.get_ptr();
            size_type n = size;
            try {
                for (; n > 0; --n, ++first) {
                    serialization::deserialize(first, in);
                }
                vec._size = size;
            } catch (...) {
                // TODO move stream backward to maintain weak guarantee
                destruct(vec.get_ptr(), first);
                throw;
            }
        }
    }
} // namespace serialization