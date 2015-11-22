#pragma once
#include "d_img.h"
#include "d_error.h"

typedef struct _dgk_window DGK_Window;

DGK_Window* dgk_window_create(char* title,int x,int y,int width,int height,DError** error);

void dgk_window_swap(DGK_Window* window);

void dgk_window_clear_color(float red,float blue, float green, float alpha);

void dgk_window_clear_depth();

void dgk_window_free(DGK_Window* window);


