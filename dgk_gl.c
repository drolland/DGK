#ifndef __NO_SDL__

#include "dgk_gl.h"
#include <SDL.h>
#include "d_error.h"
#include "d_logger.h"



void dgk_gl_init(DError** error){
    
#ifdef __GLES__
    int result = gladLoadGLES2Loader(SDL_GL_GetProcAddress);
#else
    int result = gladLoadGLLoader(SDL_GL_GetProcAddress);
#endif
    
    if(!result) {
        if (error)
            *error = DERROR("Can't load glad functions and extensions");
        goto error;
    }
    
    DLOGI("OpenGL Version %d.%d loaded", GLVersion.major, GLVersion.minor);
    DLOGI("GPU : %s %s",glGetString(GL_VENDOR),glGetString(GL_RENDERER));        
    
    DLOGI("OpenGL extensions");
    DLOGI("GL_ARB_vertex_buffer_object : %d", GLAD_GL_ARB_vertex_buffer_object);
    DLOGI("GL_ARB_vertex_array_object : %d", GLAD_GL_ARB_vertex_array_object);
    DLOGI("GL_OES_vertex_array_object : %d", GLAD_GL_OES_vertex_array_object);
    
    glEnable(GL_CULL_FACE);
    
    error:
    return;
}

#endif