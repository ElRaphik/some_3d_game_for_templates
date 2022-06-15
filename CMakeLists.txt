cmake_minimum_required(VERSION 3.22)
project(some_3d_game)

set(CMAKE_CXX_STANDARD 17)

add_executable(some_3d_game app/main.cpp game_engine/windowing_system/Window.cpp game_engine/windowing_system/Window.h app/AppWindow.cpp app/AppWindow.h game_engine/graphics_engine/GraphicsEngine.cpp game_engine/graphics_engine/GraphicsEngine.h game_engine/graphics_engine/swap_chain/SwapChain.cpp game_engine/graphics_engine/swap_chain/SwapChain.h game_engine/graphics_engine/device_context/DeviceContext.cpp game_engine/graphics_engine/device_context/DeviceContext.h)

# Create library link a executable
target_link_libraries(some_3d_game d3dcompiler d3d11 dxgi gdi32)