#ifndef COLLISSION_SHAPE
#define COLLISSION_SHAPE

#include "../vec2.hpp"
#include <allegro5/color.h>
#include <optional>

struct SquareCollissionShape;
struct CircleCollissionShape;

struct CollissionShape {
    ALLEGRO_COLOR draw_color = {0, 0, 1.0, 0.5};
    virtual void draw_shape() = 0;
    virtual std::optional<Vec2> overlap(CollissionShape *other) = 0;
    virtual std::optional<Vec2> overlap(SquareCollissionShape *other) = 0;
    virtual std::optional<Vec2> overlap(CircleCollissionShape *other) = 0;
    virtual ~CollissionShape() = default;
};

#endif