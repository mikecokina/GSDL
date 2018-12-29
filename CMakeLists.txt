cmake_minimum_required(VERSION 3.13)
project(GSDL)

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIRS}
)

add_executable(
        GSDL
        src/main.cpp
        src/Game.h
        src/Game.cpp
        src/TextureManager.h
        src/Texturemanager.cpp src/GameObject.h src/GameObject.cpp src/Map.h src/Map.cpp src/EntityComponentSys.h src/Components.h)

target_link_libraries(
        GSDL
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
)
