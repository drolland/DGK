#pragma once

#include "d_error.h"

enum {
    DIMG_COLOR_FORMAT_RGB = 3,
    DIMG_COLOR_FORMAT_RGBA = 4
};

typedef struct _dimg {
    int color_format;
    int width;
    int height;
    int pitch;
    unsigned char* pixels;
} DImg;

/* Convenient pixels acces macro*/

#define PIXEL_R(img,x,y) img->pixels[(x)*img->color_format+(y)*img->pitch]
#define PIXEL_G(img,x,y) img->pixels[(x)*img->color_format+(y)*img->pitch+1]
#define PIXEL_B(img,x,y) img->pixels[(x)*img->color_format+(y)*img->pitch+2]
#define PIXEL_A(img,x,y) img->pixels[(x)*img->color_format+(y)*img->pitch+3]

DImg* dimg_new_image(int width,int height,int color_format);

void dimg_free(DImg* image);

DImg* dimg_load_from_bmp_file(char* filepath,DError** error);

DImg* dimg_resize(DImg* img,int width,int height);