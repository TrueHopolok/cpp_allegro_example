#ifndef CIRCLE_COLLISSION_SHAPE
#define CIRCLE_COLLISSION_SHAPE

#include "../vec2.hpp"
#include "collission_shape.hpp"

struct CircleCollissionShape : public CollissionShape {
    Vec2 center;
    Vec2 radius;

    void draw_shape();
    Vec2 overlap(CollissionShape *other);
    Vec2 overlap(SquareCollissionShape *other);
    Vec2 overlap(CircleCollissionShape *other);
};

#endif