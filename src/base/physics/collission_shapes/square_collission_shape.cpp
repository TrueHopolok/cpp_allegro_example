#include "square_collission_shape.hpp"
#include "circle_collission_shape.hpp"
#include "intersection_circle_square.hpp"
#include <algorithm>
#include <allegro5/allegro_primitives.h>
#include <cmath>
#include <stdexcept>

void SquareCollissionShape::draw_shape() {
    Vec2 half = size / 2;
    al_draw_filled_rectangle(center.x - half.x, center.y - half.y,
                             center.x + half.x, center.y + half.y, draw_color);
}

std::optional<Vec2> SquareCollissionShape::overlap(CollissionShape *other) {
    if (other == nullptr)
        throw std::invalid_argument("given collission shape is nullptr");
    if (auto *specified = dynamic_cast<SquareCollissionShape *>(other))
        return overlap(specified);
    if (auto *specified = dynamic_cast<CircleCollissionShape *>(other))
        return overlap(specified);
    throw std::invalid_argument("unknown or unhandled collission shape type");
}

std::optional<Vec2>
SquareCollissionShape::overlap(SquareCollissionShape *other) {
    Vec2 half = size / 2;
    Vec2 other_half = other->size / 2;

    Vec2 this_left = center - half;
    Vec2 other_left = other->center - other_half;

    Vec2 this_right = center + half;
    Vec2 other_right = other->center + other_half;

    Vec2 MTV;

    bool overlap_x = false;
    if (this_left.x <= other_left.x) {
        if (this_right.x >= other_left.x) {
            // overlap on x
            overlap_x = true;
            MTV.x = std::min(other_right.x - this_left.x,
                             this_right.x - other_left.x);
        }
    } else {
        if (this_left.x <= other_right.x) {
            // overlap in x
            overlap_x = true;
            MTV.x = std::min(this_right.x - other_left.x,
                             other_right.x - this_left.x);
        }
    }

    bool overlap_y = false;
    if (this_left.y <= other_left.y) {
        if (this_right.y >= other_left.y) {
            // overlap on y
            overlap_y = true;
            MTV.y = std::min(other_right.y - this_left.y,
                             this_right.y - other_left.y);
        }
    } else {
        if (this_left.y <= other_right.y) {
            // overlap in y
            overlap_y = true;
            MTV.y = std::min(this_right.y - other_left.y,
                             other_right.y - this_left.y);
        }
    }

    if (overlap_x && overlap_y) {
        if (MTV.x < MTV.y) {
            MTV.y = 0;
            if (center.x < other->center.x)
                MTV.x *= -1.0;
        } else {
            MTV.x = 0;
            if (center.y < other->center.y)
                MTV.y *= -1.0;
        }
        return MTV;
    }

    return {};
}

std::optional<Vec2>
SquareCollissionShape::overlap(CircleCollissionShape *other) {
    std::optional<Vec2> MTV =
        collission_shape_intersection::circle_square(other, this);
    if (MTV.has_value())
        MTV.value() *= -1.0;
    return MTV;
}