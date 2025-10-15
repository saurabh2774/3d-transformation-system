#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
#include <cmath>


class Vector3D {
public:
    float x, y, z;

    Vector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) {}

    Vector3D operator+(const Vector3D& v) const { return Vector3D(x + v.x, y + v.y, z + v.z); }
    Vector3D operator-(const Vector3D& v) const { return Vector3D(x - v.x, y - v.y, z - v.z); }
    Vector3D operator*(float scalar) const { return Vector3D(x * scalar, y * scalar, z * scalar); }
    Vector3D operator/(float scalar) const { return (scalar != 0.0f) ? Vector3D(x / scalar, y / scalar, z / scalar) : Vector3D(); }
    Vector3D operator-() const { return Vector3D(-x, -y, -z); }

    float dot(const Vector3D& v) const { return x * v.x + y * v.y + z * v.z; }
    Vector3D cross(const Vector3D& v) const {
        return Vector3D(
            y * v.z - z * v.y,
            z * v.x - x * v.z,
            x * v.y - y * v.x
        );
    }

    float magnitude() const { return std::sqrt(x * x + y * y + z * z); }
    void normalize() {
        float mag = magnitude();
        if (mag > 0.0f) { x /= mag; y /= mag; z /= mag; }
    }
    Vector3D normalized() const { Vector3D r = *this; r.normalize(); return r; }
};

inline std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
    os << "Vector3D(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

#endif 
