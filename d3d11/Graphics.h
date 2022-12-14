//
// Created by yuxuw on 9/11/2022.
//

#ifndef GRAPHICS_GRAPHICS_H
#define GRAPHICS_GRAPHICS_H

#include "pch.h"

/*
 * This is the core class for all graphics related stuff.
 * Window creation and DirectX Device creation will be started here, in addition to other
 * core initialization tasks.
 */
class Graphics {
public:
    Graphics(HINSTANCE, UINT width, UINT height);
    virtual ~Graphics() = default;

    LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

    int InitWindows();
    int InitDirectX();
    int Run();

    virtual void InitGraphics() = 0;
    virtual void UpdateGraphics() = 0;
    virtual void RenderGraphics() = 0;
    virtual void RenderImgui() { };

    virtual void HandleCharKeys(WPARAM) { };
    virtual void HandleMouseDown(WPARAM, int, int) { };
    virtual void HandleMouseUp(WPARAM, int, int) { };
    virtual void HandleMouseMove(WPARAM, int, int) { };

protected:
    Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> d3dDeviceContext;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView> rtv;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView> depthStencilView;
    Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain;

private:
    HINSTANCE hInstance;
    HWND mainWindow;
    UINT width;
    UINT height;
    UINT clientWidth;
    UINT clientHeight;
    __int64 refreshFrequency;
};


#endif //GRAPHICS_GRAPHICS_H
