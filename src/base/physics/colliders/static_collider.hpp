#ifndef STATIC_COLLIDER
#define STATIC_COLLIDER

#include "collider.hpp"

class StaticCollider : public Collider {
  private:
    using Collider::is_sensor;
    using Collider::is_static;

  public:
    StaticCollider() {
        is_sensor = false;
        is_static = true;
    }
};

#endif