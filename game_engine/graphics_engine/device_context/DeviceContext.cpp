//
// Created by ElRaphik on 14/06/2022.
//

#include "DeviceContext.h"
#include "../swap_chain/SwapChain.h"

DeviceContext::DeviceContext(ID3D11DeviceContext *device_context) : m_device_context(device_context) {

}



DeviceContext::~DeviceContext() {

}

bool DeviceContext::release() {
    m_device_context->Release();
    delete this;
    return true;
}

bool DeviceContext::clearRenderTarget(SwapChain *swap_chain, float red, float green, float blue, float alpha) {
    FLOAT clearColor[] = {red, green, blue, alpha};
    m_device_context->ClearRenderTargetView(swap_chain->m_rtv, clearColor);


    return true;
}


