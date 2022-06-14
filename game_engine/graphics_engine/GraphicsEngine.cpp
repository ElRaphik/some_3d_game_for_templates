//
// Created by ElRaphik on 25/05/2022.
//

#include "GraphicsEngine.h"
#include "swap_chain/SwapChain.h"


GraphicsEngine::GraphicsEngine() {

}

bool GraphicsEngine::init() {
    D3D_DRIVER_TYPE driverTypes[]={
            D3D_DRIVER_TYPE_HARDWARE,
            D3D_DRIVER_TYPE_WARP,
            D3D_DRIVER_TYPE_REFERENCE
    };
    UINT numDriverTypes = ARRAYSIZE(driverTypes);

    D3D_FEATURE_LEVEL featureLevels[] = {
            D3D_FEATURE_LEVEL_11_0
    };
    UINT numFeatureLevels = ARRAYSIZE(featureLevels);

    HRESULT res=0;

    for(UINT driverTypeIndex=0; driverTypeIndex < numDriverTypes;) {

        res = D3D11CreateDevice(nullptr, driverTypes[driverTypeIndex], nullptr, NULL, featureLevels, numFeatureLevels, D3D11_SDK_VERSION, &m_d3dDevice,
                          &m_featureLevel, &m_immContext);

        if(SUCCEEDED(res)) break;

        ++driverTypeIndex;
    }

    if(FAILED(res)) return false;

    m_d3dDevice->QueryInterface(__uuidof(IDXGIDevice), (void**)&m_dxgi_device);
    m_dxgi_device->GetParent(__uuidof(IDXGIAdapter), (void**) &m_dxgi_adapter);
    m_dxgi_adapter->GetParent(__uuidof(IDXGIFactory), (void**) &m_dxgi_factory);

//    return !FAILED(res); // better way to do this

    return true;
}

bool GraphicsEngine::release() {
    m_dxgi_device->Release();
    m_dxgi_adapter->Release();
    m_dxgi_factory->Release();

    m_immContext->Release();
    m_d3dDevice->Release();
    return true;
}

GraphicsEngine::~GraphicsEngine() {

}

GraphicsEngine *GraphicsEngine::get() {
    static GraphicsEngine engine;
    return &engine;
}

SwapChain *GraphicsEngine::createSwapChain() {
    return new SwapChain();
}
