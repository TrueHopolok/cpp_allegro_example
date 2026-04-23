#ifndef VEC2
#define VEC2

#include <cmath>

const double TOO_SMALL_LENGTH = 0.00001;

struct Vec2 {
    double x = 0;
    double y = 0;
    Vec2() {}
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
    Vec2 operator*(const double coef) const { return Vec2(x * coef, y * coef); }
    Vec2 operator/(const double coef) const { return Vec2(x / coef, y / coef); }
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
    Vec2 operator*=(const double coef) {
        x *= coef;
        y *= coef;
        return (*this);
    }
    Vec2 operator/=(const double coef) {
        x /= coef;
        y /= coef;
        return (*this);
    }
    double length_squared() const { return x * x + y * y; }
    double length() const { return std::sqrt(length_squared()); }
    Vec2 normalize() const {
        const double len = length();
        if (len <= TOO_SMALL_LENGTH) {
            return Vec2(0, 0);
        }
        return operator/(len);
    }
    Vec2 normalize_self() { return *this = normalize(); }
    Vec2 direction_to(const Vec2 point) const {
        return (*this - point).normalize();
    }
};

#endif