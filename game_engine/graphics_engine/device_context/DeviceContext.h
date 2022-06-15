//
// Created by ElRaphik on 14/06/2022.
//

#ifndef SOME_3D_GAME_DEVICECONTEXT_H
#define SOME_3D_GAME_DEVICECONTEXT_H
#pragma once

#include <d3d11.h>

class SwapChain;

class DeviceContext {

public:
    DeviceContext(ID3D11DeviceContext* device_context);

    /**
     * Releases the context
     * @return True if it was released
     */
    bool release();

    bool clearRenderTarget(SwapChain *swap_chain, float red, float green, float blue, float alpha);

    ~DeviceContext();

private:
    ID3D11DeviceContext* m_device_context;

};


#endif //SOME_3D_GAME_DEVICECONTEXT_H
