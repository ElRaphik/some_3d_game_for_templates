//
// Created by ElRaphik on 25/05/2022.
//

#include "Window.h"

Window* window = nullptr;

Window::Window() {

}

Window::~Window() {

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam){
    switch (msg) {
        case WM_CREATE:
            // Event fired when the window will be created
            window->onCreate();
            break;
        case WM_DESTROY: {
            // Event fired when the window will be destroyed
            window->onDestroy();
            ::PostQuitMessage(0);
            break;
        }

        default:
            return ::DefWindowProcA(hwnd, msg, wparam, lparam);
    }
}

bool Window::init() {
    // Setting up WNDCLASSEX object
    WNDCLASSEX wc;
    wc.cbClsExtra = NULL;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.cbWndExtra = NULL;
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hInstance = nullptr;
    wc.lpszClassName = TEXT("MyWindowClass");
    wc.lpszMenuName = TEXT("");
    wc.style = NULL;
    wc.lpfnWndProc = &WndProc;

    if(!::RegisterClassEx(&wc)) return false; // if registration of previous object fails, return false

    if(!window) window = this;

    // Creation of the window
    m_hwnd = ::CreateWindowExA(WS_EX_OVERLAPPEDWINDOW, TEXT(wc.lpszClassName), TEXT("DirectX Application"),
                      WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768,
                      nullptr, nullptr, nullptr, nullptr);

    if(!m_hwnd) return false; // if the creation fails (m_hwnd==0) return false

    // show up the window
    ::ShowWindow(m_hwnd, SW_SHOW);
    ::UpdateWindow(m_hwnd);

    m_isRun = true;

    return true;
}

bool Window::broadcast() {
    MSG msg;

    while(::PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE) > 0) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }

    window->onUpdate();

    Sleep(0);

    return true;
}

bool Window::release() {
    // Destroy the window
    if(!::DestroyWindow(m_hwnd)) return false;

    return true;
}

bool Window::isRun() {
    return m_isRun;
}

void Window::onDestroy() {
    m_isRun = false;
}


