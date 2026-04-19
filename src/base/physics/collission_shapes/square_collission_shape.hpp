#ifndef SQUARE_COLLISSION_SHAPE
#define SQUARE_COLLISSION_SHAPE

#include "../vec2.hpp"
#include "collission_shape.hpp"

struct SquareCollissionShape : public CollissionShape {
    Vec2 center;
    Vec2 width;
    Vec2 height;

    void draw_shape();
    Vec2 overlap(CollissionShape *other);
    Vec2 overlap(SquareCollissionShape *other);
    Vec2 overlap(CircleCollissionShape *other);
};

#endif