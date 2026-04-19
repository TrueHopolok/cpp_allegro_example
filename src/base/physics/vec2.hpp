#ifndef VEC2
#define VEC2

#include <cmath>

struct Vec2 {
    double x = 0;
    double y = 0;
    Vec2(double x, double y) : x(x), y(y) {}
    Vec2 operator+(const Vec2 other) const {
        return Vec2(x + other.x, y + other.y);
    }
    Vec2 operator-(const Vec2 other) const {
        return Vec2(x - other.x, y - other.y);
    }
    Vec2 operator*(const Vec2 other) const {
        return Vec2(x * other.x, y * other.y);
    }
    Vec2 &operator+=(const Vec2 other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    Vec2 &operator-=(const Vec2 other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    Vec2 &operator*=(const Vec2 other) {
        x *= other.x;
        y *= other.y;
        return *this;
    }
    double length_squared() const { return x * x + y * y; }
    double length() const { return sqrt(length_squared()); }
};

#endif