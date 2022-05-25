//
// Created by ElRaphik on 25/05/2022.
//

#ifndef SOME_3D_GAME_GRAPHICSENGINE_H
#define SOME_3D_GAME_GRAPHICSENGINE_H
#pragma once

#include <d3d11.h>

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

private:
    ID3D11Device* m_d3dDevice;
    D3D_FEATURE_LEVEL m_featureLevel;
    ID3D11DeviceContext* m_immContext;
};


#endif //SOME_3D_GAME_GRAPHICSENGINE_H
