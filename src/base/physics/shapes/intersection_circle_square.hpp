#ifndef INTERSECTION_CIRCLE_SQUARE
#define INTERSECTION_CIRCLE_SQUARE

#include "../vec2.hpp"
#include "circle_collission_shape.hpp"
#include "square_collission_shape.hpp"
#include <optional>

namespace collission_shape_intersection {
    std::optional<Vec2> circle_square(CircleCollissionShape *circle,
                                      SquareCollissionShape *square);
}

#endif