//
// Created by cFAG on 22/05/2020.
//

#pragma once

#include <windows.h>

class OffscreenBuffer {
public:
    OffscreenBuffer(int width, int height);
    ~OffscreenBuffer();

    void memoryRenew();
    void resize(int width, int height);

    [[nodiscard]] BITMAPINFO *getInfo() const;
    void *getMemory() const;
    int getWidth() const;
    int getHeight() const;



private:
    BITMAPINFO *_info;
    void *_memory;
    int _width;
    int _height;
    int _bytesPerPixel;

    void memoryAlloc(int memorySize);
};
