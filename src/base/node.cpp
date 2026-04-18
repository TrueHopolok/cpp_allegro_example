#include "node.hpp"
#include "engine/game_engine.hpp"

void Node::free() { GameEngine::get_instance().remove(id); }