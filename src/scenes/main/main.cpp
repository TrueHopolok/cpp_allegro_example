#include "main.hpp"
#include "../../base/engine/game_engine.hpp"
#include "../../base/physics/vec2.hpp"
#include "../../entities/wall/wall.hpp"

void prepare_scene_main() {
    GameEngine &gm = GameEngine::get_instance();
    gm.append(
        new Wall(Vec2(10, 10), Vec2(10, 10), ALLEGRO_COLOR{0.5, 0.5, 0.5, 0.5}),
        0, 0);
}