g++ src/main.cpp ^
src/base/engine/game_engine.cpp src/base/engine/engine.cpp src/base/node.cpp ^
src/base/physics/shapes/square_collission_shape.cpp src/base/physics/shapes/circle_collission_shape.cpp src/base/physics/shapes/intersection_circle_square.cpp ^
-o build/windows/program ^
-std=c++17 ^
-Iallegro/include ^
-Lallegro/lib ^
-lallegro ^
-lallegro_main ^
-lallegro_primitives ^
-lallegro_image ^
-lallegro_font ^
-lallegro_ttf