//
// Created by ElRaphik on 14/06/2022.
//

#ifndef SOME_3D_GAME_SWAPCHAIN_H
#define SOME_3D_GAME_SWAPCHAIN_H
#pragma once

#include <d3d11.h>

class DeviceContext;

class SwapChain {
public:
    SwapChain();
    /**
     * Initialize SwapChain for a window
     * @return true if the swap chain has been successfully created
     */
    bool init(HWND hwnd, UINT width, UINT height);
    /**
     * Releases the SwapChain of a window
     * @return True each time.
     */
    bool release();
    ~SwapChain();

    bool present(bool vsync);

private:
    IDXGISwapChain* m_swap_chain;
    ID3D11RenderTargetView* m_rtv;
    ID3D11DepthStencilView* m_dsv;

    friend class DeviceContext;
};


#endif //SOME_3D_GAME_SWAPCHAIN_H
