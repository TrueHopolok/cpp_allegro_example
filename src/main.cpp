#include "base/engine/game_engine.hpp"

int main() {
    GameEngine &gm = GameEngine::get_instance();
    gm.start();
}