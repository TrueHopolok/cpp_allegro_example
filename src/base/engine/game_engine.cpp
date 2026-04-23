#include "game_engine.hpp"
#include "../node.hpp"
#include "../physics/colliders/collider.hpp"
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

void GameEngine::process(double delta_time) {
    // DELTA TIME
    if (delta_time > max_delta_time) {
        delta_time = max_delta_time;
        if (verbose) {
            std::cout << "[WARN]: game experiencing lags "
                      << "some frames might be dropped" << std::endl;
        }
    }

    // QUEUE JOIN
    while (!queue_to_join.empty()) {
        GameNode gn = queue_to_join.front();
        int id = gn.node->id;
        everyone[id] = gn;
        if (gn.is_collider) {
            colliders[id] = dynamic_cast<Collider *>(gn.node);
        }
        queue_to_join.pop();
    }

    // PROCESS PREPARE
    std::priority_queue<GameNode> process_queue;
    for (const std::pair<int, GameNode> p : everyone) {
        GameNode node = p.second;
        node.processing = true;
        process_queue.push(node);
    }

    // PROCESS UPDATE + PHYSICS PREPARE
    std::queue<Collider *> physics_queue;
    while (!process_queue.empty()) {
        Node *node = process_queue.top().node;
        if (process_queue.top().is_collider) {
            physics_queue.push(dynamic_cast<Collider *>(node));
        }
        node->process(delta_time);
        process_queue.pop();
    }

    // PHYSICS UPDATE
    while (!physics_queue.empty()) {
        Collider *current = physics_queue.front();
        physics_queue.pop();
        for (const std::pair<int, Collider *> p : colliders) {
            if (p.first == current->id)
                continue;

            std::optional<Vec2> MTV = current->shape->overlap(p.second->shape);
            if (!MTV.has_value())
                continue;

            if (current->is_sensor || p.second->is_sensor) {
                // no need to apply MTV for sensors
            } else if (!current->is_static && !p.second->is_static) {
                current->position += MTV.value() * 0.5;
                p.second->position -= MTV.value() * 0.5;
            } else {
                if (current->is_static)
                    p.second->position -= MTV.value();
                else
                    current->position += MTV.value();
            }

            // NOTE: this logic does not prevent
            // double collission per frame,
            // yet this should not happen
            current->on_collission(p.second);
            p.second->on_collission(current);
        }
    }

    // QUEUE FREE
    while (!queue_to_free.empty()) {
        int id = queue_to_free.front();
        everyone.erase(id);
        colliders.erase(id);
        queue_to_free.pop();
    }
}

void GameEngine::render() {
    std::priority_queue<GameNode, std::vector<GameNode>> process_queue;
    for (const std::pair<int, GameNode> p : everyone) {
        GameNode node = p.second;
        node.processing = false;
        process_queue.push(node);
    }
    while (!process_queue.empty()) {
        process_queue.top().node->render();
        process_queue.pop();
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
    bool is_collider = dynamic_cast<Collider *>(node) != nullptr;
    queue_to_join.push(GameNode{.node = node,
                                .processing = false,
                                .is_collider = is_collider,
                                .z_order = z_order,
                                .p_order = p_order});
}

void GameEngine::remove(int id) { queue_to_free.push(id); }