#ifndef __FONT_H__
#define __FONT_H__

#include "stdint.h"

#define _FONT_HANKEN_LIGHT_13_
#define _FONT_MAX_CHAR_SIZE_INT8_ 	132	// bytes to store biggest char (2D)
#define _FONT_MAX_CHAR_SIZE_INT32_ 	33
#define _FONT_MAX_CHAR_WIDTH_ 	20	// pix
#define _FONT_MAX_CHAR_HEIGHT_ 	17	// pix
#define _FONT_MIN_CHAR_WIDTH_ 	3	// useful for worst case num of printable chars (min advance)
#define _FONT_MAX_CHAR_ASCENT_ 	16	// max char height with respect to base line (for cursor placement)

struct font_info {
    uint32_t font_size;		// size in bytes
    uint8_t pix_depth;		// bits per pixel
    const char *font_name;
    uint8_t font_height;		// height including line spacing
    uint8_t font_ascend;		// usual ascent excluding accents
};

struct char_info {
    int8_t xoffset;		// pixel offset to top left corner
    int8_t yoffset;
    uint8_t advance;
    uint32_t address;
    uint16_t length;		// length in bytes
    uint8_t width;
    uint8_t height;
};

// latin-1 encoding!
uint8_t get_char(struct char_info *const ch_info, const uint32_t ch);

int8_t get_kerning(const uint32_t ch1, const uint32_t ch2);

void get_font_info(struct font_info *const finfo);

#endif
