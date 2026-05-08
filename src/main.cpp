#include "scenes/main/main.hpp"
#include "base/engine/game_engine.hpp"

int main() {
    prepare_scene_main();
    GameEngine &gm = GameEngine::get_instance();
    gm.start();
}