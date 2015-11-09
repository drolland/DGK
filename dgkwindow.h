#pragma once
#include "dimg.h"

typedef struct _dgk_window DGK_Window;

DGK_Window* dgk_window_create(char* title,int x,int y,int width,int height);

void dkg_window_free(DGK_Window* window);

void dgk_window_blit_image(DGK_Window* window,DImg* image,int x,int y);
