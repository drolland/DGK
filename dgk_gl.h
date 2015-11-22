#pragma once

#include "glad.h"
#include "d_error.h"

#ifdef __ANDROID__
#define __GLES__ 1
#endif

void dgk_gl_init(DError** error);



