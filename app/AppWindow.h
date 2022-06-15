//
// Created by ElRaphik on 25/05/2022.
//

#ifndef SOME_3D_GAME_APPWINDOW_H
#define SOME_3D_GAME_APPWINDOW_H
#include "../game_engine/windowing_system/Window.h"
#include "../game_engine/graphics_engine/GraphicsEngine.h"
#include "../game_engine/graphics_engine/swap_chain/SwapChain.h"
#include "../game_engine/graphics_engine/device_context/DeviceContext.h"

class AppWindow: public Window {
public:
    void onCreate() override;

    void onUpdate() override;

    void onDestroy() override;

private:
    SwapChain* m_swap_chain;

};


#endif //SOME_3D_GAME_APPWINDOW_H
