cmake_minimum_required(VERSION 2.6)
project(FODENGINE)

add_library(fodengine
 src/FODENGINE/dummy.cpp
)
target_link_libraries(fodengine SDL2 opengl32 glew32)

add_executable(game
 src/game/main.cpp
)
target_link_libraries(game fodengine)