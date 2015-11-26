#pragma once
#include "d_error.h"


void dgk_window_create(char* title,int x,int y,int width,int height,DError** error);

void dgk_window_swap();

void dgk_window_clear_color(float red,float blue, float green, float alpha);

void dgk_window_clear_depth();



