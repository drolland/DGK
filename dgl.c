#include "dgl.h"
#include <SDL2/SDL.h>
#include "derror.h"
#include "dlogger.h"

void dgl_init(DError** error){
    
    if(!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
        if (error)
            *error = DERROR(DERROR_UNKNOW_ERROR,"Can't load gl functions and extensions");
        goto error;
    }
    
    DLOGI("OpenGL Version %d.%d loaded", GLVersion.major, GLVersion.minor);

            
    
    error:
    return;
}

