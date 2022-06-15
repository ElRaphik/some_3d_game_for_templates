//
// Created by ElRaphik on 14/06/2022.
//

#include "SwapChain.h"
#include "../GraphicsEngine.h"

SwapChain::SwapChain() {

}

bool SwapChain::init(HWND hwnd, UINT width, UINT height) {
    // basically we just get the device through the GraphicsEngine class
    auto* device = reinterpret_cast<ID3D11Device *>(GraphicsEngine::get()->m_dxgi_device);

    // create descriptor by first zero-ing it to avoid side effects, then we just define our own values for each field
    DXGI_SWAP_CHAIN_DESC descriptor;
    ZeroMemory(&descriptor, sizeof(descriptor));
    descriptor.BufferCount = 1;
    descriptor.BufferDesc.Width = width;
    descriptor.BufferDesc.Height = height;
    descriptor.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    descriptor.BufferDesc.RefreshRate.Numerator = 60;
    descriptor.BufferDesc.RefreshRate.Denominator = 1;
    descriptor.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    descriptor.OutputWindow = hwnd;
    descriptor.SampleDesc.Count = 1;
    descriptor.SampleDesc.Quality = 0;
    descriptor.Windowed = true;

    // create the swap chain for the window we want, on our device, with our descriptor
    HRESULT res = GraphicsEngine::get()->m_dxgi_factory->CreateSwapChain(device, &descriptor, &m_swap_chain);

    if(FAILED(res)) return false;

    ID3D11Texture2D* buffer = nullptr;
    res = m_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&buffer);

    if(FAILED(res)) return false;

    // FIXME 01: line below fails, try to investigate why
    res = device->CreateRenderTargetView(buffer, NULL, &m_rtv);
    buffer->Release();

    if(FAILED(res)) return false;

    return true;
}

bool SwapChain::release() {
    m_swap_chain->Release();
    delete this;
    return true;
}

SwapChain::~SwapChain() {

}

bool SwapChain::present(bool vsync) {
    m_swap_chain->Present(vsync, NULL);

    return true;
}
