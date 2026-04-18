#ifndef GAME_ENGINE
#define GAME_ENGINE

#include "engine.hpp"
#include <map>
#include <queue>

class Node;

class GameEngine : public Engine {
  private:
    struct GameNode {
        bool proccessing;
        Node *node;
        int z_order; // render layer, less means earlier
        int p_order; // process layer, more means earlier
        bool operator<(const GameNode other) const {
            return proccessing ? p_order < other.p_order
                               : z_order > other.z_order;
        }
    };

    std::queue<GameNode> joinable;
    std::map<int, GameNode> everyone;

    GameEngine() : Engine(640, 360, 60, true) {}

    void process(double delta_time) override;
    void render() override;
    int get_id();

  public:
    static GameEngine &get_instance();

    void append(Node *node, int p_order, int z_order);
    void remove(int id);
};
#endif