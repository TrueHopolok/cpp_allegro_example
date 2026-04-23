#include "circle_collission_shape.hpp"
#include "intersection_circle_square.hpp"
#include "square_collission_shape.hpp"
#include <allegro5/allegro_primitives.h>
#include <cmath>
#include <stdexcept>

void CircleCollissionShape::draw_shape() {
    al_draw_filled_circle(center.x, center.y, radius, draw_color);
}

std::optional<Vec2> CircleCollissionShape::overlap(CollissionShape *other) {
    if (other == nullptr)
        throw std::invalid_argument("given collission shape is nullptr");
    if (auto *specified = dynamic_cast<SquareCollissionShape *>(other))
        return overlap(specified);
    if (auto *specified = dynamic_cast<CircleCollissionShape *>(other))
        return overlap(specified);
    throw std::invalid_argument("unknown or unhandled collission shape type");
}

std::optional<Vec2>
CircleCollissionShape::overlap(SquareCollissionShape *other) {
    return collission_shape_intersection::circle_square(this, other);
}

std::optional<Vec2>
CircleCollissionShape::overlap(CircleCollissionShape *other) {
    double dx = center.x - other->center.x;
    double dy = center.y - other->center.y;

    double dist_squared = dx * dx + dy * dy;
    double radii_sum = radius + other->radius;

    if (dist_squared >= radii_sum * radii_sum)
        return {};

    double dist = std::sqrt(dist_squared);
    double depth = radii_sum - dist;

    // otherwise direction will return {0,0} causing Vec2.ZERO as a result
    if (dist <= TOO_SMALL_LENGTH)
        return Vec2(depth, 0);

    return other->center.direction_to(center) * depth;
}