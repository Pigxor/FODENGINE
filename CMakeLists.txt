cmake_minimum_required(VERSION 2.6)
project(FODENGINE)

include_directories(src)

add_library(fodengine
 src/FODENGINE/engine.cpp
 src/FODENGINE/engine.h
 src/FODENGINE/entity.cpp
 src/FODENGINE/entity.h
 src/FODENGINE/component.cpp
 src/FODENGINE/component.h
 src/FODENGINE/Renderer.cpp
 src/FODENGINE/Renderer.h
 src/FODENGINE/triangle.cpp
 src/FODENGINE/Exception.cpp
 src/FODENGINE/Exception.h
 src/FODENGINE/Transform.cpp
 src/FODENGINE/Transform.h
 src/FODENGINE/Camera.cpp
 src/FODENGINE/Camera.h
)
target_link_libraries(fodengine SDL2 opengl32 glew32)

add_executable(game
 src/game/main.cpp
)
target_link_libraries(game fodengine)