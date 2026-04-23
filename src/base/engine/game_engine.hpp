#ifndef GAME_ENGINE
#define GAME_ENGINE

#include "engine.hpp"
#include <map>
#include <queue>

class Node;
class Collider;

class GameEngine : public Engine {
  private:
    struct GameNode {
        Node *node;
        bool processing;
        bool is_collider;
        int z_order; // render layer, less means earlier
        int p_order; // process layer, more means earlier
        bool operator<(const GameNode other) const {
            return processing ? p_order < other.p_order
                              : z_order > other.z_order;
        }
    };

    std::queue<GameNode> queue_to_join;
    std::queue<int> queue_to_free;
    std::map<int, GameNode> everyone;
    std::map<int, Collider *> colliders;

    double max_delta_time;

    GameEngine() : Engine(640, 360, 60, true) {
        max_delta_time = 1.0 / fps * 2;
    }
    ~GameEngine() {}

    void process(double delta_time) override;
    void render() override;
    int get_id();

  public:
    static GameEngine &get_instance();

    void append(Node *node, int p_order, int z_order);
    void remove(int id);
};
#endif