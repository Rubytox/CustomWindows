//
// Created by cFAG on 22/05/2020.
//

#include "OffscreenBuffer.h"

/* ==============================[ CONSTRUCTORS ]============================== */

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

    _bgColor = 0;
    _activeColor = RGBToColor(0xFF, 0, 0);

    resize(width, height);
}

/* ==============================[ DESTRUCTORS ]============================== */
OffscreenBuffer::~OffscreenBuffer() {
    free(_info);
    memoryRenew();
}


/* ==============================[ GETTERS-SETTERS ]============================== */
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

void OffscreenBuffer::setColor(uint8_t R, uint8_t G, uint8_t B) {
    _activeColor = RGBToColor(R, G, B);
}

OffscreenBuffer::pixel_t *OffscreenBuffer::getFirstPixel() const {
    return (pixel_t *) _memory;
}

OffscreenBuffer::pixel_t *OffscreenBuffer::getOuterBound() const {
    int nbPixels = _width * _height;
    return getFirstPixel() + nbPixels;
}

OffscreenBuffer::pixel_t *OffscreenBuffer::getPixel(int x, int y) const {
    pixel_t *firstPixel = getFirstPixel();

    // Seems like I can't multiply pointers as we do with sum operator...
    // Todo: look into that
    int col = 0;
    while (col++ < y)
        firstPixel += _width;
    return firstPixel + x;
}

/* ==============================[ UTILITARIES ]============================== */
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

OffscreenBuffer::color_t OffscreenBuffer::RGBToColor(uint8_t R, uint8_t G, uint8_t B) {
    return (R << 16u)
           | (G << 8u)
           | B;
}


/* ==============================[ DRAWING WRAPPERS ]============================== */

void OffscreenBuffer::drawPixel(int x, int y, uint8_t R, uint8_t G, uint8_t B) {
    drawPixel(x, y, RGBToColor(R, G, B));
}

void OffscreenBuffer::drawRect(int x, int y, int width, int height, uint8_t R, uint8_t G, uint8_t B) {
    /*
     * This method draws the following border :
     *        (x, y)                    (x+width, y)
     *              +------------------+
     *              |                  |
     *              |                  |
     *              |                  |
     *              +------------------+
     * (x, y+height)                    (x+width, y+height)
     */

    color_t color = RGBToColor(R, G, B);
    drawRect(x, y, width, height, color);
}

void OffscreenBuffer::drawLine(int xStart, int yStart, int xEnd, int yEnd, uint8_t R, uint8_t G, uint8_t B) {
    drawLine(xStart, yStart, xEnd, yEnd, RGBToColor(R, G, B));
}
void OffscreenBuffer::drawLine(int xStart, int yStart, int xEnd, int yEnd) {
    drawLine(xStart, yStart, xEnd, yEnd, _activeColor);
}

void OffscreenBuffer::fill(uint8_t R, uint8_t G, uint8_t B) {
    fill(RGBToColor(R, G, B));
}

void OffscreenBuffer::clear() {
    fill(_bgColor);
}

void OffscreenBuffer::drawPixel(int x, int y) {
    drawPixel(x, y, _activeColor);
}

void OffscreenBuffer::drawRect(int x, int y, int width, int height) {
    drawRect(x, y, width, height, _activeColor);
}

/* ==============================[ DRAWING INTERNALS ]============================== */

void OffscreenBuffer::drawPixel(int x, int y, color_t color) {
    if (x < 0 || x >= _width ||
        y < 0 || y >= _height) {
        // TODO: handle error case
        return;
    }

    *getPixel(x, y) = color;
}

void OffscreenBuffer::drawRect(int x, int y, int width, int height, OffscreenBuffer::color_t color) {
    for (int xPos = x; xPos < x + width; xPos++) {
        drawPixel(xPos, y, color);
    }
    for (int yPos = y; yPos < y + height; yPos++) {
        drawPixel(x, yPos, color);
    }
    for (int xPos = x; xPos < x + width; xPos++) {
        drawPixel(xPos, y + height, color);
    }
    for (int yPos = y; yPos < y + height; yPos++) {
        drawPixel(x + width, yPos, color);
    }
}

void OffscreenBuffer::fill(OffscreenBuffer::color_t color) {
    for (pixel_t *pixel = getFirstPixel();
         pixel < getOuterBound();
         pixel++) {
        *pixel = color;
    }
}

/**
 * Bresenham algorithm.
 *
 * @param xStart
 * @param yStart
 * @param xEnd
 * @param yEnd
 * @param color
 */
void OffscreenBuffer::drawLine(int xStart, int yStart, int xEnd, int yEnd, OffscreenBuffer::color_t color) {
    int dx, dy, p, x, y;
    dx = xEnd - xStart;
    dy = yEnd - yStart;
    x = xStart;
    y = yStart;
    p = 2*dy-dx;

    while(x < xEnd)
    {
        drawPixel(x,y,color);
        if(p>=0)
        {
            y++;
            p += 2 * dy - 2 * dx;
        }
        else
            p += 2 * dy;
        x++;
    }
}

