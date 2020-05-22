//
// Created by cFAG on 22/05/2020.
//

#include "OffscreenBuffer.h"

OffscreenBuffer::OffscreenBuffer(int width, int height) : _width(width), _height(height), _memory(nullptr) {
    _info = (BITMAPINFO *) malloc(sizeof(BITMAPINFO));

    _info->bmiHeader.biSize = sizeof(_info->bmiHeader);
    _info->bmiHeader.biWidth = width;
    _info->bmiHeader.biHeight = -height;  // In order for the image to be top-down we need height < 0
    _info->bmiHeader.biPlanes = 1;
    _info->bmiHeader.biBitCount = 32;
    _info->bmiHeader.biCompression = BI_RGB;
    _info->bmiHeader.biSizeImage = 0;
    _info->bmiHeader.biXPelsPerMeter = 0;
    _info->bmiHeader.biYPelsPerMeter = 0;
    _info->bmiHeader.biClrUsed = 0;
    _info->bmiHeader.biClrImportant = 0;

    _bytesPerPixel = _info->bmiHeader.biBitCount / 8;

    resize(width, height);
}

OffscreenBuffer::~OffscreenBuffer() {
    free(_info);
    memoryRenew();
}

void OffscreenBuffer::memoryRenew() {
    if (_memory)
        VirtualFree(_memory, 0, MEM_RELEASE);
}

void OffscreenBuffer::memoryAlloc(int memorySize) {
    _memory = VirtualAlloc(nullptr,
                           memorySize,
                           MEM_COMMIT,
                           PAGE_READWRITE);
}

void OffscreenBuffer::resize(int width, int height) {
    memoryRenew();

    _width = width;
    _height = height;
    _info->bmiHeader.biWidth = width;
    _info->bmiHeader.biHeight = -height;  // In order for the image to be top-down we need height < 0

    int memorySize = (width * height) * _bytesPerPixel;
    memoryAlloc(memorySize);
}

BITMAPINFO *OffscreenBuffer::getInfo() const {
    return _info;
}

void *OffscreenBuffer::getMemory() const {
    return _memory;
}

int OffscreenBuffer::getWidth() const {
    return _width;
}

int OffscreenBuffer::getHeight() const {
    return _height;
}
