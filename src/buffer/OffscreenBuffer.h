//
// Created by cFAG on 22/05/2020.
//

#pragma once

#include <Windows.h>

#include <cstdint>

class OffscreenBuffer {
    typedef uint32_t pixel_t;
    typedef uint32_t color_t;
public:
    OffscreenBuffer(int width, int height);
    ~OffscreenBuffer();

    void memoryRenew();
    void resize(int width, int height);

    [[nodiscard]] BITMAPINFO *getInfo() const;
    [[nodiscard]] void *getMemory() const;
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;

    void setColor(uint8_t R, uint8_t G, uint8_t B);

    void drawPixel(int x, int y,
                   uint8_t R, uint8_t G, uint8_t B);
    void drawPixel(int x, int y);

    void drawRect(int x, int y,
                  int width, int height,
                  uint8_t R, uint8_t G, uint8_t B);
    void drawRect(int x, int y,
                  int width, int height);

    void drawLine(int xStart, int yStart,
                  int xEnd, int yEnd,
                  uint8_t R, uint8_t G, uint8_t B);

    void drawLine(int xStart, int yStart,
                  int xEnd, int yEnd);

    void fill(uint8_t R, uint8_t G, uint8_t B);

    void clear();



private:
    BITMAPINFO *_info;
    void *_memory;
    int _width;
    int _height;
    int _bytesPerPixel;

    color_t _bgColor;
    color_t _activeColor;

    void memoryAlloc(int memorySize);

    [[nodiscard]] pixel_t *getFirstPixel() const;
    [[nodiscard]] pixel_t *getOuterBound() const;
    [[nodiscard]] pixel_t *getPixel(int x, int y) const;

    void drawPixel(int x, int y, color_t color);
    void drawRect(int x, int y, int width, int height, color_t color);
    void drawLine(int xStart, int yStart,
                  int xEnd, int yEnd,
                  color_t color);

    static color_t RGBToColor(uint8_t R, uint8_t G, uint8_t B) ;

    void fill(color_t color);
};
