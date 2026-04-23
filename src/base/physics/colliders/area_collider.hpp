#ifndef AREA_COLLIDER
#define AREA_COLLIDER

#include "collider.hpp"

class AreaCollider : public Collider {
  private:
    using Collider::is_sensor;
    using Collider::is_static;

  public:
    AreaCollider() {
        is_sensor = true;
        is_static = false;
    }
};

#endif