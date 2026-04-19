#include "node.hpp"
#include "engine/game_engine.hpp"

void Node::process(double delta_time) { (void)delta_time; }

void Node::render() {}

void Node::free() { GameEngine::get_instance().remove(id); }