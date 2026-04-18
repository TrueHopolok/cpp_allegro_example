#ifndef VECTOR2
#define VECTOR2

#include <cmath>

struct Vector2 {
    double x = 0;
    double y = 0;
    Vector2(double x, double y) : x(x), y(y) {}
    Vector2 operator+(const Vector2 other) const {
        return Vector2(x + other.x, y + other.y);
    }
    Vector2 operator-(const Vector2 other) const {
        return Vector2(x - other.x, y - other.y);
    }
    Vector2 operator*(const Vector2 other) const {
        return Vector2(x * other.x, y * other.y);
    }
    Vector2 &operator+=(const Vector2 other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    Vector2 &operator-=(const Vector2 other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    Vector2 &operator*=(const Vector2 other) {
        x *= other.x;
        y *= other.y;
        return *this;
    }
    double length_squared() const { return x * x + y * y; }
    double length() const { return sqrt(length_squared()); }
};

#endif