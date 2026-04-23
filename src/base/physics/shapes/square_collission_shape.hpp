#ifndef SQUARE_COLLISSION_SHAPE
#define SQUARE_COLLISSION_SHAPE

#include "../vec2.hpp"
#include "collission_shape.hpp"

struct SquareCollissionShape : public CollissionShape {
    Vec2 center;
    Vec2 size;

    void draw_shape();
    std::optional<Vec2> overlap(CollissionShape *other);
    std::optional<Vec2> overlap(SquareCollissionShape *other);
    std::optional<Vec2> overlap(CircleCollissionShape *other);
};

#endif