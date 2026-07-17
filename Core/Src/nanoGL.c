/*

File:   nanoGL.c
Author: Isaac Pawley

*/

#include "nanoGL.h"

#include "fonts.h"
#include "matrix.h"

#define FONT_FIRST_CHAR 32
#define FONT_LAST_CHAR  126

uint16_t nanoGL_stringWidth(const char *text, const Font_t *font) {
    uint16_t width = 0;

    while (*text) {
        uint8_t index = (uint8_t)*text - FONT_FIRST_CHAR;

        if (index <= (FONT_LAST_CHAR - FONT_FIRST_CHAR)) {
            width += font->char_width[index];
        }
        width++;
        text++;
    }

    return width;
}

static void nanoGL_drawChar(int16_t x, int16_t y, char c, const Font_t *font) {
    if ((uint8_t)c < FONT_FIRST_CHAR || (uint8_t)c > FONT_LAST_CHAR) {
        c = '?';
    }

    uint8_t index = (uint8_t)c - FONT_FIRST_CHAR;

    for (uint8_t row = 0; row < font->height; row++) {
        const uint16_t bits = font->data[index * font->width + row];

        for (uint8_t col = 0; col < font->char_width[index]; col++) {
            if (bits & (0x80 >> col)) {
                matrix_setPixel(x + col, y + row, MATRIX_ON);
            }
        }
    }
}

void nanoGL_drawString(int16_t x, int16_t y, const char *text, const Font_t *font) {
    while (*text) {
        uint8_t index = (uint8_t)*text - FONT_FIRST_CHAR;

        if (index < (FONT_LAST_CHAR - FONT_FIRST_CHAR + 1)) {
            nanoGL_drawChar(x, y, *text, font);

            x += font->char_width[index];
        }

        x += 1;

        text++;
    }
}

void nanoGL_clear(void) {
    for (uint8_t y = 0; y < PHYSICAL_ROWS; y++) {
        for (uint8_t x = 0; x < PHYSICAL_COLS; x++) {
            matrix_setPixel(x, y, MATRIX_OFF);
        }
    }
}

void nanoGL_drawBitmap(int16_t x, int16_t y, const unsigned char* bitmap, uint8_t w, uint8_t h) {
    int16_t byteWidth = (w + 7) / 8;
    uint8_t byte = 0;

    for (uint8_t row = 0; row < h; row++, y++) {
        for (uint8_t col = 0; col < w; col++) {
            if (col & 7) {
                byte <<= 1;
            } else {
                byte = (*(const unsigned char *)(&bitmap[row * byteWidth + col / 8]));
            }

            if (byte & 0x80) {
                matrix_setPixel(x + col, y, MATRIX_ON);
            }
        }
    }
}