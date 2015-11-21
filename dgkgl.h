#pragma once

#include "glad.h"
#include "derror.h"

#ifdef __ANDROID__
#define __GLES__ 1
#endif

void dgk_gl_init(DError** error);



