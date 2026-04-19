#ifndef COLLIDER
#define COLLIDER

#include "../node.hpp"
#include "collission_shapes/collission_shape.hpp"
#include <cstdint>

class Collider : public Node {
  public:
    CollissionShape *shape;

    // Other nodes can detect this collider.
    // This means, this object won't recieve on_collission call.
    uint32_t layer;

    // This collider can detect other nodes.
    // This means, this object won't recieve on_collission call.
    uint32_t mask;

    // This collider won't be moved when 2 nodes collide
    // NOTE: Collider in this case should not move.
    bool immovable;

    // This is a trigger collider, thus won't move
    // both self and collided node.
    bool sensor;

    // Called if 2 nodes collide.
    // Method will be called after
    // all nodes recieved `process` call.
    void on_collission();
};

#endif