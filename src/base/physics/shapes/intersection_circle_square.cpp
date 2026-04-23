#include "intersection_circle_square.hpp"
#include <algorithm>

std::optional<Vec2>
collission_shape_intersection::circle_square(CircleCollissionShape *circle,
                                             SquareCollissionShape *square) {
    Vec2 half = square->size / 2;

    double clamp_x = std::clamp(circle->center.x, square->center.x - half.x,
                                square->center.x + half.x);
    double clamp_y = std::clamp(circle->center.y, square->center.y - half.y,
                                square->center.y + half.y);

    double dx = circle->center.x - clamp_x;
    double dy = circle->center.y - clamp_y;

    double dist_squared = dx * dx + dy * dy;

    if (dist_squared >= circle->radius * circle->radius)
        return {};

    double dist = std::sqrt(dist_squared);
    double depth = circle->radius - dist;

    // otherwise direction will return {0,0} causing Vec2.ZERO as a result
    if (dist <= TOO_SMALL_LENGTH)
        return Vec2(depth, 0);

    return Vec2(clamp_x, clamp_y).direction_to(circle->center) * depth;
}