//
// Created by ElRaphik on 25/05/2022.
//

#ifndef SOME_3D_GAME_GRAPHICSENGINE_H
#define SOME_3D_GAME_GRAPHICSENGINE_H
#pragma once

#include <d3d11.h>
#include "device_context/DeviceContext.h"

class SwapChain;
class DeviceContext;

class GraphicsEngine {
public:
    // STATIC METHODS
    /**
     * Getter for the engine, basic and easy way to make this a singleton
     * @return The address of the gameEngine singleton
     */
    static GraphicsEngine* get();

    // INSTANCE METHODS
    GraphicsEngine();
    /**
     * Initialize the graphics engine
     * @return True if the initialization is completed, false otherwise
     */
    bool init();
    /**
     * Releases the graphics engine entity
     * @return True if the engine was successfully released
     */
    bool release();
    ~GraphicsEngine();

    SwapChain* createSwapChain();

    DeviceContext* getImmediateDeviceContext();

private:
    DeviceContext* m_imm_device_context;

    ID3D11Device* m_d3dDevice;
    D3D_FEATURE_LEVEL m_featureLevel;
//    ID3D11DeviceContext* m_immContext; //not needed anymore

    IDXGIDevice* m_dxgi_device;
    IDXGIAdapter* m_dxgi_adapter;
    IDXGIFactory* m_dxgi_factory;

    friend class SwapChain;
};


#endif //SOME_3D_GAME_GRAPHICSENGINE_H
