//
// Created by ElRaphik on 14/06/2022.
//

#ifndef SOME_3D_GAME_SWAPCHAIN_H
#define SOME_3D_GAME_SWAPCHAIN_H

#include <d3d11.h>


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

private:
    IDXGISwapChain* m_swap_chain;
};


#endif //SOME_3D_GAME_SWAPCHAIN_H
