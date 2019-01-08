#ifndef CORE_MATH_VECTOR4_HPP_INCLUDE
#define CORE_MATH_VECTOR4_HPP_INCLUDE

class Vector4 {
public:
    float x = 0;
    float y = 0;
    float z = 0;
    float w = 0;

    Vector4() = default;
    Vector4(float x, float y, float z, float w);

    float& component(int);
    float const& component(int) const;

    Vector4& operator-();
    Vector4 operator-() const;
    Vector4& operator+=(Vector4 const&);
    Vector4& operator-=(Vector4 const&);
    Vector4& operator*=(float);

    // Check if all components are equal 0
    bool is_zero() const;

    float length_squared() const;
    float length() const;

    // If vector is non-zero, normalizes the vector.
    // Otherwise leaves it unchanged
    Vector4& normalize();

    Vector4& scale(float);
    Vector4& multiply_componentwise(Vector4 const&);
};

Vector4 operator+(Vector4 const&, Vector4 const&);
Vector4 operator-(Vector4 const&, Vector4 const&);
Vector4 operator*(Vector4 const&, float);
void swap(Vector4&, Vector4&);

// If vector is non-zero, returns normalized copy of the vector.
// Otherwise returns zero vector
Vector4 normalize(Vector4);

Vector4 multiply_componentwise(Vector4 const&, Vector4 const&);

#endif // !CORE_MATH_VECTOR4_HPP_INCLUDE
