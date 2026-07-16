/*

File:   nanoGL.h
Author: Isaac Pawley

*/

#ifndef INC_NANOGL_H_
#define INC_NANOGL_H_

#include "fonts.h"

void nanoGL_drawString(uint8_t x, uint8_t y, const char *text, const Font_t *font);
void nanoGL_clear(void);

#endif /* INC_NANOGL_H_ */