#ifndef NODE
#define NODE

#include "physics/vec2.hpp"

class GameEngine;

class Node {
  private:
    friend class GameEngine;
    int id;

  public:
    Vec2 position;
    void process(double delta_time);
    void render();
    void free();
    virtual ~Node() = default;
};

#endif