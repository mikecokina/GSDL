cmake_minimum_required(VERSION 3.13)
project(GSDL)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

add_executable(GSDL src/main.cpp src/Game.h src/Game.cpp)
target_link_libraries(GSDL ${SDL2_LIBRARIES})