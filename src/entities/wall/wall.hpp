#ifndef ENTITY_WALL
#define ENTITY_WALL

#include "../../base/physics/colliders/static_collider.hpp"
#include "../../base/physics/shapes/square_collission_shape.hpp"
#include <allegro5/color.h>

class Wall : public StaticCollider {
  private:
    void draw_update();

  public:
    Wall(Vec2 center, Vec2 size, ALLEGRO_COLOR color) {
        auto square_shape = new SquareCollissionShape();
        square_shape->center = center;
        square_shape->size = size;
        square_shape->draw_color = color;
        shape = square_shape;
    }

    ~Wall() {
        //
        delete shape;
    }
};

#endif