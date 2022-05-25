cmake_minimum_required(VERSION 3.22)
project(some_3d_game)

set(CMAKE_CXX_STANDARD 17)

add_executable(some_3d_game app/main.cpp game_engine/Window.cpp game_engine/Window.h app/AppWindow.cpp app/AppWindow.h)
