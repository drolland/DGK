#ifndef __NO_SDL__

#include "dgl.h"
#include <SDL.h>
#include "derror.h"
#include "dlogger.h"

void dgl_init(DError** error){
    
    if(!gladLoadGLES2Loader(SDL_GL_GetProcAddress)) {
        if (error)
            *error = DERROR("Can't load glad functions and extensions");
        goto error;
    }
    
    DLOGI("OpenGL Version %d.%d loaded", GLVersion.major, GLVersion.minor);
    DLOGI("GPU : %s %s",glGetString(GL_VENDOR),glGetString(GL_RENDERER));        
    
    DLOGI("OpenGL extensions");
    DLOGI("GL_ARB_vertex_buffer_object : %d", GLAD_GL_ARB_vertex_buffer_object);
    DLOGI("GL_OES_vertex_array_object : %d", GLAD_GL_OES_vertex_array_object);
    
    
    error:
    return;
}

#endif