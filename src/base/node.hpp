#ifndef NODE
#define NODE

#include "vector2.hpp"

class GameEngine;

class Node {
  private:
    friend class GameEngine;
    int id;

  public:
    Vector2 position;
    virtual void process(double delta_time) = 0;
    virtual void render() = 0;
    void free();
};

#endif