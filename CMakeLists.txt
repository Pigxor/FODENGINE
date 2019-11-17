cmake_minimum_required(VERSION 2.6)
project(FODENGINE)

include_directories(src)


add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp

)
if(MSVC)
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()

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
 src/FODENGINE/Transform.cpp
 src/FODENGINE/Transform.h
 src/FODENGINE/Camera.cpp
 src/FODENGINE/Camera.h
 src/FODENGINE/stb_image.h
)
target_link_libraries(fodengine SDL2 rend)

add_executable(game
 src/game/main.cpp
)
target_link_libraries(game fodengine)