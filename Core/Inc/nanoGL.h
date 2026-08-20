/*

File:   nanoGL.h
Author: Isaac Pawley

*/

#ifndef INC_NANOGL_H_
#define INC_NANOGL_H_

#include "fonts.h"

uint16_t nanoGL_stringWidth(const char *text, const Font_t *font);
void nanoGL_drawString(int16_t x, int16_t y, const char *text, const Font_t *font);
void nanoGL_clear(void);
void nanoGL_drawBitmap(int16_t x, int16_t y, const unsigned char* bitmap, uint8_t w, uint8_t h);
void nanoGL_drawFilledRectangle(int16_t x1, int16_t y1, uint8_t x2, uint8_t y2);

#endif /* INC_NANOGL_H_ */