#include <windows.h>

#include <iostream>
#include <cstdint>

#include "Logger.h"
#include "OffscreenBuffer.h"

#define internal static
#define local_persist static
#define global static


/*
 * +=========+
 * | GLOBALS |
 * +=========+
 */

Logger *logger = new Logger(R"(C:\Users\cFAG\Documents\HandmadeHero\log.txt)");
global bool isRunning;

/*
 * +=========+
 * | METHODS |
 * +=========+
 */

typedef struct {
    int width;
    int height;
} windowDimensions;

internal windowDimensions
Win32GetWindowDimensions(HWND window)
{
    RECT clientRect;
    GetClientRect(window, &clientRect);
    int width = clientRect.right - clientRect.left;
    int height = clientRect.bottom - clientRect.top;

    return {width, height};
}


internal void
Win32RenderWeirdGradient(const OffscreenBuffer& buffer, int xOffset, int yOffset)
{
    int nbPixels = buffer.getWidth() * buffer.getHeight();
    uint32_t *lastPixel = (uint32_t *) buffer.getMemory() + nbPixels;
    int x = 0;
    int y = 0;
    for (auto *pixel = (uint32_t *) buffer.getMemory();
         pixel < lastPixel;
         pixel++) {
        /*
         * Pixel structure is : X R G B
         */
        uint8_t R = 0;
        uint8_t G = y + yOffset;
        uint8_t B = x + xOffset;
        *pixel = (R << 16u)
                 | (G << 8u)
                 | B;
        x++;
        if (x == buffer.getWidth()) {
            y++;
            x = 0;
        }
    }
};

internal void
Win32UpdateWindow(const OffscreenBuffer &buffer, HDC deviceContext, int width, int height)
{
    StretchDIBits(deviceContext,
                  /*
                  x, y, width, height,   // dest
                  x, y, width, height,   // src
                   */
                  0, 0, width, height,
                  0, 0, buffer.getWidth(), buffer.getHeight(),
                  buffer.getMemory(),
                  buffer.getInfo(),
                  DIB_RGB_COLORS, SRCCOPY);
}

/**
 * This function handles the messages provided by the thing that uses
 * the window.
 */
LRESULT CALLBACK
Win32MainWindowCallback(HWND window,
                        UINT message,
                        WPARAM wParam,
                        LPARAM lParam)
{
    LRESULT result = 0;

    switch (message) {
    case WM_SIZE:
    break;

    case WM_DESTROY:
    case WM_CLOSE:
        isRunning = false;
        break;

    case WM_ACTIVATEAPP:
        logger->info("WM_ACTIVATEAPP");
        break;

    case WM_PAINT:
    {
        PAINTSTRUCT paint;
        HDC deviceContext = BeginPaint(window, &paint);

        windowDimensions dimensions = Win32GetWindowDimensions(window);
        auto *buffer = (OffscreenBuffer *) GetWindowLongPtrA(window, GWLP_USERDATA);
        Win32UpdateWindow(*buffer, deviceContext, dimensions.width, dimensions.height);

        EndPaint(window, &paint);
    } break;

    default:
        result = DefWindowProc(window, message, wParam, lParam);
        break;
    }

    return result;
}

int CALLBACK
WinMain(HINSTANCE instance,
        HINSTANCE prevInstance,
        LPSTR commandLine,
        int showCode)
{
    logger->info("Started program");

    WNDCLASS windowClass = {};


    windowClass.style = CS_HREDRAW | CS_VREDRAW;
    windowClass.lpfnWndProc = Win32MainWindowCallback;
    windowClass.hInstance = instance;
    windowClass.lpszClassName = "HandmadeHeroWindowClass";

    if (RegisterClass(&windowClass)) {
        HWND window = CreateWindowExA(
                0,
                windowClass.lpszClassName,
                "Handmade Hero",
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                CW_USEDEFAULT,
                CW_USEDEFAULT,
                CW_USEDEFAULT,
                CW_USEDEFAULT,
                nullptr,
                nullptr,
                instance,
                nullptr);

        if (window) {
            windowDimensions dimensions = {1200, 700};
            auto *buffer = new OffscreenBuffer(dimensions.width, dimensions.height);
            SetWindowLongPtrA(window, GWLP_USERDATA, (LONG) buffer);

            isRunning = true;
            int xOffset = 0;
            int yOffset = 0;

            while (isRunning) {
                MSG message;
                while (PeekMessageA(&message, 0, 0, 0, PM_REMOVE)) {
                    if (message.message == WM_QUIT)
                        isRunning = false;

                    TranslateMessage(&message);
                    DispatchMessageA(&message);
                }

                auto *buffer = (OffscreenBuffer *) GetWindowLongPtrA(window, GWLP_USERDATA);
                Win32RenderWeirdGradient(*buffer, xOffset, yOffset);

                HDC deviceContext = GetDC(window);
                windowDimensions dimensions = Win32GetWindowDimensions(window);
                Win32UpdateWindow(*buffer, deviceContext, dimensions.width, dimensions.height);
                ReleaseDC(window, deviceContext);

                xOffset--;
                yOffset++;
            }

            // We're not running anymore

            delete buffer;
        }
        else {
            logger->error("Couldn't create window");
        }
    }
    else {
        logger->error("Registering failed");
    }

    delete logger;


    return 0;
}

