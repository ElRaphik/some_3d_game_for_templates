//
// Created by ElRaphik on 25/05/2022.
//

#ifndef SOME_3D_GAME_WINDOW_H
#define SOME_3D_GAME_WINDOW_H
#pragma once
#include <windows.h>

class Window {

public:
    Window();
    /**
     * Initialise and create the Window
     * @return True if the creation is successful, false otherwise
     */
    bool init();
    /**
     * Basic update method
     * @return True
     */
    bool broadcast();

    /**
     * Destroys the Window
     * @return True if there was a window to destroy and it has been successfully destroyed, false otherwise
     */
    bool release();
    /**
     * Just to know if the app is running
     * @return True if the app is running
     */
    bool isRun();

    // EVENTS
    virtual void onCreate();
    virtual void onUpdate();
    virtual void onDestroy();

    ~Window();

protected:
    HWND m_hwnd;
    bool m_isRun;
};


#endif //SOME_3D_GAME_WINDOW_H
