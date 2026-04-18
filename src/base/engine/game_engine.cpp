#include "game_engine.hpp"
#include "../node.hpp"
#include <queue>
#include <utility>
#include <vector>

void GameEngine::process(double delta_time) {
    std::priority_queue<GameNode, std::vector<GameNode>> process_queue;
    for (const std::pair<int, GameNode> p : everyone) {
        GameNode node = p.second;
        node.proccessing = true;
        process_queue.push(node);
    }
    while (!process_queue.empty()) {
        process_queue.top().node->process(delta_time);
        process_queue.pop();
    }
}

void GameEngine::render() {
    std::priority_queue<GameNode, std::vector<GameNode>> process_queue;
    for (const std::pair<int, GameNode> p : everyone) {
        GameNode node = p.second;
        node.proccessing = false;
        process_queue.push(node);
    }
    while (!process_queue.empty()) {
        process_queue.top().node->render();
        process_queue.pop();
    }

    // happens at the end of the frame
    while (!joinable.empty()) {
        everyone[joinable.front().node->id] = joinable.front();
        joinable.pop();
    }
}

int GameEngine::get_id() {
    static int id = 0;
    return id++;
}

GameEngine &GameEngine::get_instance() {
    static GameEngine global_instance = GameEngine();
    return global_instance;
}

void GameEngine::append(Node *node, int p_order, int z_order) {
    node->id = get_id();
    joinable.push(GameNode{false, node, z_order, p_order});
}

void GameEngine::remove(int id) { everyone.erase(id); }