#ifndef CIRCLE_COLLISSION_SHAPE
#define CIRCLE_COLLISSION_SHAPE

#include "../vec2.hpp"
#include "collission_shape.hpp"

struct CircleCollissionShape : public CollissionShape {
    Vec2 center;
    double radius;

    void draw_shape();
    std::optional<Vec2> overlap(CollissionShape *other);
    std::optional<Vec2> overlap(SquareCollissionShape *other);
    std::optional<Vec2> overlap(CircleCollissionShape *other);
};

#endif