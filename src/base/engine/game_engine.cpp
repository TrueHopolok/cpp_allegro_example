#include "game_engine.hpp"
#include "../node.hpp"
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

void GameEngine::process(double delta_time) {
    if (delta_time > max_delta_time) {
        delta_time = max_delta_time;
        if (verbose) {
            std::cout << "[WARN]: game experiencing lags "
                      << "some frames might be dropped" << std::endl;
        }
    }
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
    while (!queue_to_free.empty()) {
        everyone.erase(queue_to_free.front());
        queue_to_free.pop();
    }
    while (!queue_to_join.empty()) {
        everyone[queue_to_join.front().node->id] = queue_to_join.front();
        queue_to_join.pop();
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
    queue_to_join.push(GameNode{false, node, z_order, p_order});
}

void GameEngine::remove(int id) { queue_to_free.push(id); }