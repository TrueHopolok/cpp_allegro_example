#ifndef BODY_COLLIDER
#define BODY_COLLIDER

#include "collider.hpp"

class BodyCollider : public Collider {
  private:
    using Collider::is_sensor;
    using Collider::is_static;

  public:
    BodyCollider() {
        is_sensor = false;
        is_static = false;
    }
};

#endif