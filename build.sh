g++ src/main.cpp \
src/base/engine/game_engine.cpp src/base/engine/engine.cpp src/base/node.cpp \
src/base/physics/shapes/square_collission_shape.cpp src/base/physics/shapes/circle_collission_shape.cpp src/base/physics/shapes/intersection_circle_square.cpp \
-o build/linux/program \
-std=c++17 \
$(pkg-config --cflags --libs allegro-5 allegro_primitives-5 allegro_image-5 allegro_font-5 allegro_ttf-5)