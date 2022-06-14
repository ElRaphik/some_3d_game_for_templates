//
// Created by ElRaphik on 25/05/2022.
//

#include "AppWindow.h"

void AppWindow::onCreate() {
    Window::onCreate();
    GraphicsEngine::get()->init();
    m_swap_chain = GraphicsEngine::get()->createSwapChain();

    RECT rc = getClientWindowRect();
    m_swap_chain->init(m_hwnd, rc.right - rc.left, rc.top - rc.bottom);
}

void AppWindow::onUpdate() {
    Window::onUpdate();
}

void AppWindow::onDestroy() {
    Window::onDestroy();
    m_swap_chain->release();
    GraphicsEngine::get()->release();
}
