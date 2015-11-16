#include "dgl.h"
#include <SDL2/SDL.h>
#include "derror.h"
#include "dlogger.h"

void dgl_init(DError** error){
    
    if(!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
        if (error)
            *error = DERROR("Can't load glad functions and extensions");
        goto error;
    }
    
    DLOGI("OpenGL Version %d.%d loaded", GLVersion.major, GLVersion.minor);
    DLOGI("GPU : %s %s",glGetString(GL_VENDOR),glGetString(GL_RENDERER));        
    
    DLOGI("OpenGL extensions");
    DLOGI("GL_ARB_vertex_buffer_object : %d", GLAD_GL_ARB_vertex_buffer_object);
    if ( !GLAD_GL_ARB_vertex_buffer_object ){
        if ( error)
            *error = DERROR("GL_ARB_vertex_buffer_object is mandatory");
        goto error;
    }
    
    error:
    return;
}

