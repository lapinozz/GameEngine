#include <anton_assert.hpp>

namespace anton_engine::anton_stl {
    template <typename T, typename Allocator>
    inline Vector<T, Allocator>::Vector() {
        _data = allocate(_capacity);
    }

    template <typename T, typename Allocator>
    inline Vector<T, Allocator>::Vector(size_type const n) {
        _capacity = math::max(_capacity, n);
        _data = allocate(_capacity);
        try {
            anton_stl::uninitialized_default_construct_n(_data, n);
            _size = n;
        } catch (...) {
            deallocate(_data, _capacity);
            throw;
        }
    }

    template <typename T, typename Allocator>
    inline Vector<T, Allocator>::Vector(anton_stl::Reserve_Tag, size_type const n): _capacity(n) {
        _data = allocate(_capacity);
    }

    template <typename T, typename Allocator>
    inline Vector<T, Allocator>::Vector(size_type n, value_type const& value) {
        _capacity = math::max(_capacity, n);
        _data = allocate(_capacity);
        try {
            anton_stl::uninitialized_fill_n(_data, n, value);
            _size = n;
        } catch (...) {
            deallocate(_data, _capacity);
            throw;
        }
    }

    template <typename T, typename Allocator>
    inline Vector<T, Allocator>::Vector(Vector const& v): _allocator(v._allocator), _capacity(v._capacity) {
        _data = allocate(_capacity);
        try {
            anton_stl::uninitialized_copy_n(v._data, v._size, _data);
            _size = v._size;
        } catch (...) {
            deallocate(_data, _capacity);
            throw;
        }
    }

    template <typename T, typename Allocator>
    inline Vector<T, Allocator>::Vector(Vector&& v) noexcept: _allocator(std::move(v._allocator)), _capacity(v._capacity), _size(v._size), _data(v._data) {
        v._data = nullptr;
        v._capacity = 0;
        v._size = 0;
    }

    template <typename T, typename Allocator>
    template <typename... Args>
    inline Vector<T, Allocator>::Vector(Variadic_Construct_Tag, Args&&... args) {
        _capacity = math::max(_capacity, static_cast<size_type>(sizeof...(Args)));
        _data = allocate(_capacity);
        try {
            anton_stl::uninitialized_variadic_construct(_data, anton_stl::forward<Args>(args)...);
            _size = static_cast<size_type>(sizeof...(Args));
        } catch (...) {
            deallocate(_data, _capacity);
            throw;
        }
    }

    template <typename T, typename Allocator>
    inline Vector<T, Allocator>::~Vector() {
        if (_data != nullptr) {
            anton_stl::destruct_n(_data, _size);
            deallocate(_data, _capacity);
        }
    }

    template <typename T, typename Allocator>
    inline Vector<T, Allocator>& Vector<T, Allocator>::operator=(Vector const& v) {
        static_assert(std::allocator_traits<Allocator>::propagate_on_container_copy_assignment::value, "Allocator is not copy assignable");
        _allocator = v._allocator;
        T* new_storage = allocate(v._capacity);
        try {
            anton_stl::uninitialized_copy_n(v._data, v._size, new_storage);
        } catch (...) {
            deallocate(new_storage, v._capacity);
            throw;
        }
        anton_stl::destruct_n(_data, _size);
        // Note: assumes v._allocator == _allocator is true
        deallocate(_data, _capacity);
        _data = new_storage;
        _size = v._size;
        _capacity = v._capacity;
        return *this;
    }

    template <typename T, typename Allocator>
    inline Vector<T, Allocator>& Vector<T, Allocator>::operator=(Vector&& v) noexcept {
        // Note: We ignore the fact that the allocator_traits<Allocator>::propagate_on_container_swap might be false
        // or the allocators do not compare equal.
        swap(_data, v._data);
        swap(_allocator, v._allocator);
        swap(_capacity, v._capacity);
        swap(_size, v._size);
        return *this;
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::operator[](size_type index) -> reference {
        return *get_ptr(index);
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::operator[](size_type index) const -> const_reference {
        return *get_ptr(index);
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::front() -> reference {
        return *get_ptr(0);
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::front() const -> const_reference {
        return *get_ptr(0);
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::back() -> reference {
        return *get_ptr(_size - 1);
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::back() const -> const_reference {
        return *get_ptr(_size - 1);
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::data() -> pointer {
        return get_ptr();
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::data() const -> const_pointer {
        return get_ptr();
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::begin() -> iterator {
        return iterator(get_ptr());
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::end() -> iterator {
        return iterator(get_ptr(_size));
    }
    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::begin() const -> const_iterator {
        return const_iterator(get_ptr());
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::end() const -> const_iterator {
        return const_iterator(get_ptr(_size));
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::cbegin() const -> const_iterator {
        return const_iterator(get_ptr());
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::cend() const -> const_iterator {
        return const_iterator(get_ptr(_size));
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::rbegin() -> reverse_iterator {
        return reverse_iterator(end());
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::rend() -> reverse_iterator {
        return reverse_iterator(begin());
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::crbegin() const -> reverse_const_iterator {
        return reverse_const_iterator(cend());
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::crend() const -> reverse_const_iterator {
        return reverse_const_iterator(cbegin());
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::size() const -> size_type {
        return _size;
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::capacity() const -> size_type {
        return _capacity;
    }

    template <typename T, typename Allocator>
    inline void Vector<T, Allocator>::resize(size_type n, value_type const& value) {
        ensure_capacity(n);
        if (n > _size) {
            anton_stl::uninitialized_fill(get_ptr(_size), get_ptr(n), value);
        } else {
            anton_stl::destruct(get_ptr(n), get_ptr(_size));
        }
        _size = n;
    }

    template <typename T, typename Allocator>
    inline void Vector<T, Allocator>::resize(size_type n) {
        ensure_capacity(n);
        if (n > _size) {
            anton_stl::uninitialized_default_construct(get_ptr(_size), get_ptr(n));
        } else {
            anton_stl::destruct(get_ptr(n), get_ptr(_size));
        }
        _size = n;
    }

    template <typename T, typename Allocator>
    inline void Vector<T, Allocator>::reserve(size_type n) {
        ensure_capacity(n);
    }

    template <typename T, typename Allocator>
    inline void Vector<T, Allocator>::set_capacity(size_type new_capacity) {
        if (new_capacity != _capacity) {
            T* new_data = allocate(new_capacity);
            try {
                // TODO: More reallocation options
                if constexpr (std::is_nothrow_move_constructible_v<T>) {
                    anton_stl::uninitialized_move_n(_data, math::min(new_capacity, _size), new_data);
                } else {
                    anton_stl::uninitialized_copy_n(_data, math::min(new_capacity, _size), new_data);
                }
            } catch (...) { deallocate(new_data, new_capacity); }
            destruct_n(_data, _size);
            deallocate(_data, _capacity);
            _data = new_data;
            _capacity = new_capacity;
            _size = math::min(new_capacity, _size);
        }
    }

    template <typename T, typename Allocator>
    template <typename Input_Iterator>
    inline void Vector<T, Allocator>::assign(Input_Iterator first, Input_Iterator last) {
        ensure_capacity(last - first);
        destruct_n(_data, _size);
        copy(first, last, _data);
        _size = last - first;
    }

    template <typename T, typename Allocator>
    inline void Vector<T, Allocator>::insert_unsorted(const_iterator position, value_type const& value) {
        ANTON_ASSERT(get_iterator_underlying_ptr(position) >= get_ptr() && get_iterator_underlying_ptr(position) <= get_ptr(_size),
                     "Vector::insert invalid iterator");

        ensure_capacity(_size + 1);
        size_type offset = static_cast<size_type>(get_iterator_underlying_ptr(position) - _data);
        if (offset == _size) {
            attempt_construct(get_ptr(offset), value);
            ++_size;
        } else {
            T* elem_ptr = get_ptr(offset);
            if constexpr (std::is_nothrow_move_constructible_v<T>) {
                attempt_move(elem_ptr, get_ptr(_size));
            } else {
                attempt_copy(elem_ptr, get_ptr(_size));
            }
            anton_stl::destruct(elem_ptr);
            attempt_construct(elem_ptr, value);
            ++_size;
        }
    }

    template <typename T, typename Allocator>
    inline void Vector<T, Allocator>::push_back(value_type const& val) {
        ensure_capacity(_size + 1);
        T* elem_ptr = get_ptr(_size);
        attempt_construct(elem_ptr, val);
        ++_size;
    }

    template <typename T, typename Allocator>
    inline void Vector<T, Allocator>::push_back(value_type&& val) {
        ensure_capacity(_size + 1);
        T* elem_ptr = get_ptr(_size);
        attempt_construct(elem_ptr, std::move(val));
        ++_size;
    }

    template <typename T, typename Allocator>
    template <typename... CtorArgs>
    inline auto Vector<T, Allocator>::emplace_back(CtorArgs&&... args) -> reference {
        ensure_capacity(_size + 1);
        T* elem_ptr = get_ptr(_size);
        attempt_construct(elem_ptr, std::forward<CtorArgs>(args)...);
        ++_size;
        return *elem_ptr;
    }

    template <typename T, typename Allocator>
    inline void Vector<T, Allocator>::erase_unsorted(size_type index) {
        if (index > _size) {
            throw std::out_of_range("index out of range");
        }

        erase_unsorted_unchecked(index);
    }

    template <typename T, typename Allocator>
    inline void Vector<T, Allocator>::erase_unsorted_unchecked(size_type index) {
        T* elem_ptr = get_ptr(index);
        T* last_elem_ptr = get_ptr(_size - 1);
        if (elem_ptr != last_elem_ptr) { // Prevent self move-assignment
            *elem_ptr = anton_stl::move(*last_elem_ptr);
        }
        anton_stl::destruct(last_elem_ptr);
        --_size;
    }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::erase_unsorted(const_iterator iter) -> iterator {
#if ANTON_ITERATOR_DEBUG

#endif // !ANTON_ITERATOR_DEBUG

        auto pos = const_cast<value_type*>(iter);
        if (iter != cend() - 1) {
            *pos = anton_stl::move(*get_ptr(_size - 1));
        }
        anton_stl::destruct(get_ptr(_size - 1));
        _size -= 1;
        return pos;
    }

    //     template <typename T, typename Allocator>
    //     inline auto Vector<T, Allocator>::erase_unsorted(const_iterator first, const_iterator last) -> iterator {
    // #if ANTON_ITERATOR_DEBUG

    // #endif // ANTON_ITERATOR_DEBUG

    //         if (first != last) {
    //             auto first_last_elems = last - first;
    //             auto last_end_elems = end() - last;
    //             auto elems_till_end = math::min(first_last_elems, last_end_elems);
    //             anton_stl::move(end() - elems_till_end, end(), first);
    //             anton_stl::destruct(end() - elems_till_end, end());
    //             _size -= first_last_elems;
    //         }

    //         return first;
    //     }

    template <typename T, typename Allocator>
    inline auto Vector<T, Allocator>::erase(const_iterator first, const_iterator last) -> iterator {
#if ANTON_ITERATOR_DEBUG

#endif // ANTON_ITERATOR_DEBUG

        if (first != last) {
            iterator pos = anton_stl::move(const_cast<value_type*>(last), end(), const_cast<value_type*>(first));
            anton_stl::destruct(pos, end());
            _size -= last - first;
        }

        return const_cast<value_type*>(first);
    }

    template <typename T, typename Allocator>
    inline void Vector<T, Allocator>::pop_back() {
        ANTON_VERIFY(_size > 0, "Trying to pop an element from an empty Array.");
        T* last_elem_ptr = get_ptr(_size - 1);
        anton_stl::destruct(last_elem_ptr);
        --_size;
    }

    template <typename T, typename Allocator>
    inline void Vector<T, Allocator>::clear() {
        anton_stl::destruct(get_ptr(), get_ptr(_size));
        _size = 0;
    }

    template <typename T, typename Allocator>
    inline void Vector<T, Allocator>::attempt_copy(T* from, T* to) {
        ::new (to) T(*from);
    }

    template <typename T, typename Allocator>
    inline void Vector<T, Allocator>::attempt_move(T* from, T* to) {
        ::new (to) T(std::move(*from));
    }

    template <typename T, typename Allocator>
    template <typename... Ctor_Args>
    inline void Vector<T, Allocator>::attempt_construct(T* in, Ctor_Args&&... args) {
        if constexpr (std::is_constructible_v<T, Ctor_Args&&...>) {
            ::new (in) T(std::forward<Ctor_Args>(args)...);
        } else {
            ::new (in) T{std::forward<Ctor_Args>(args)...};
        }
    }

    template <typename T, typename Allocator>
    inline T* Vector<T, Allocator>::get_ptr(size_type index) {
        return std::launder(_data + index);
    }

    template <typename T, typename Allocator>
    inline T const* Vector<T, Allocator>::get_ptr(size_type index) const {
        return std::launder(_data + index);
    }

    template <typename T, typename Allocator>
    inline T* Vector<T, Allocator>::get_iterator_underlying_ptr(iterator const& iter) {
        return anton_stl::addressof(*iter);
    }

    // Exists to simplify changing the iterator type
    template <typename T, typename Allocator>
    inline T const* Vector<T, Allocator>::get_iterator_underlying_ptr(const_iterator const& iter) const {
        return anton_stl::addressof(*iter);
    }

    template <typename T, typename Allocator>
    inline T* Vector<T, Allocator>::allocate(size_type const size) {
        void* mem = _allocator.allocate(size * static_cast<isize>(sizeof(T)), static_cast<isize>(alignof(T)));
        return static_cast<T*>(mem);
    }

    template <typename T, typename Allocator>
    inline void Vector<T, Allocator>::deallocate(void* mem, size_type const size) {
        _allocator.deallocate(mem, size * static_cast<isize>(sizeof(T)), static_cast<isize>(alignof(T)));
    }

    template <typename T, typename Allocator>
    inline void Vector<T, Allocator>::ensure_capacity(size_type requested_capacity) {
        if (requested_capacity > _capacity) {
            size_type new_capacity = _capacity;
            while (new_capacity < requested_capacity) {
                new_capacity *= 2;
            }

            T* new_data = allocate(new_capacity);
            try {
                // TODO: More reallocation options
                if constexpr (std::is_nothrow_move_constructible_v<T>) {
                    anton_stl::uninitialized_move(_data, _data + _size, new_data);
                } else {
                    anton_stl::uninitialized_copy(_data, _data + _size, new_data);
                }
            } catch (...) { deallocate(new_data, new_capacity); }
            destruct_n(_data, _size);
            deallocate(_data, _capacity);
            _data = new_data;
            _capacity = new_capacity;
        }
    }
} // namespace anton_engine::anton_stl

namespace anton_engine {
    template <typename T, typename Allocator>
    inline void serialize(serialization::Binary_Output_Archive& out, anton_stl::Vector<T, Allocator> const& vec) {
        using size_type = typename anton_stl::Vector<T, Allocator>::size_type;
        size_type capacity = vec.capacity(), size = vec.size();
        out.write(capacity);
        out.write(size);
        for (T const& elem: vec) {
            serialize(out, elem);
        }
    }

    template <typename T, typename Allocator>
    inline void deserialize(serialization::Binary_Input_Archive& in, anton_stl::Vector<T, Allocator>& vec) {
        using size_type = typename anton_stl::Vector<T, Allocator>::size_type;
        size_type capacity, size;
        in.read(capacity);
        in.read(size);
        vec.clear();
        vec.set_capacity(capacity);
        if constexpr (std::is_default_constructible_v<T>) {
            vec.resize(size);
            try {
                for (T& elem: vec) {
                    deserialize(in, elem);
                }
            } catch (...) {
                // TODO: Move stream backwards to maintain weak guarantee
                anton_stl::destruct_n(vec.data(), size);
                throw;
            }
        } else {
            size_type n = size;
            try {
                for (; n > 0; --n) {
                    Stack_Allocate<T> elem;
                    vec.push_back(std::move(elem.reference()));
                    deserialize(in, vec.back());
                }
                vec._size = size;
            } catch (...) {
                // TODO: Move stream backwards to maintain weak guarantee
                anton_stl::destruct_n(vec.data(), size - n);
                throw;
            }
        }
    }
} // namespace anton_engine
