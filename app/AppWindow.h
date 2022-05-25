//
// Created by ElRaphik on 25/05/2022.
//

#ifndef SOME_3D_GAME_APPWINDOW_H
#define SOME_3D_GAME_APPWINDOW_H
#include "../game_engine/windowing_system/Window.h"

class AppWindow: public Window {
public:
    void onCreate() override;

    void onUpdate() override;

    void onDestroy() override;

};


#endif //SOME_3D_GAME_APPWINDOW_H
