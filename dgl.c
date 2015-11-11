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
    
    error:
    return;
}

