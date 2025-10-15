#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include "vector3d.h"
#include <cmath>
#include <iostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Matrix4x4 {
public:
    float m[4][4];

    Matrix4x4() {
        for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) m[i][j] = 0.0f;
    }

    Matrix4x4(const float arr[4][4]) {
        for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) m[i][j] = arr[i][j];
    }

    static Matrix4x4 identity() {
        Matrix4x4 result;
        for (int i = 0; i < 4; ++i) result.m[i][i] = 1.0f;
        return result;
    }

    static Matrix4x4 createTranslation(const Vector3D& t) {
        Matrix4x4 result = identity();
        result.m[0][3] = t.x;
        result.m[1][3] = t.y;
        result.m[2][3] = t.z;
        return result;
    }

    static Matrix4x4 createScale(const Vector3D& s) {
        Matrix4x4 result = identity();
        result.m[0][0] = s.x;
        result.m[1][1] = s.y;
        result.m[2][2] = s.z;
        return result;
    }

    static Matrix4x4 createRotationX(float angleDegrees) {
        float angleRad = angleDegrees * M_PI / 180.0f;
        Matrix4x4 result = identity();
        result.m[1][1] = cos(angleRad);
        result.m[1][2] = -sin(angleRad);
        result.m[2][1] = sin(angleRad);
        result.m[2][2] = cos(angleRad);
        return result;
    }

    static Matrix4x4 createRotationY(float angleDegrees) {
        float angleRad = angleDegrees * M_PI / 180.0f;
        Matrix4x4 result = identity();
        result.m[0][0] = cos(angleRad);
        result.m[0][2] = sin(angleRad);
        result.m[2][0] = -sin(angleRad);
        result.m[2][2] = cos(angleRad);
        return result;
    }

    static Matrix4x4 createRotationZ(float angleDegrees) {
        float angleRad = angleDegrees * M_PI / 180.0f;
        Matrix4x4 result = identity();
        result.m[0][0] = cos(angleRad);
        result.m[0][1] = -sin(angleRad);
        result.m[1][0] = sin(angleRad);
        result.m[1][1] = cos(angleRad);
        return result;
    }

    Matrix4x4 operator*(const Matrix4x4& other) const {
        Matrix4x4 result;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                for (int k = 0; k < 4; ++k)
                    result.m[i][j] += m[i][k] * other.m[k][j];
        return result;
    }

    Vector3D operator*(const Vector3D& v) const {
        float x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3];
        float y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3];
        float z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3];
        float w = m[3][0] * v.x + m[3][1] * v.y + m[3][2] * v.z + m[3][3];

        if (w != 0.0f && w != 1.0f) return Vector3D(x / w, y / w, z / w);
        return Vector3D(x, y, z);
    }
};

inline std::ostream& operator<<(std::ostream& os, const Matrix4x4& mat) {
    os << "Matrix4x4:\n";
    for (int i = 0; i < 4; ++i) {
        os << "[ ";
        for (int j = 0; j < 4; ++j) {
            os << mat.m[i][j] << (j == 3 ? "" : ", ");
        }
        os << " ]\n";
    }
    return os;
}

#endif // MATRIX4X4_H
