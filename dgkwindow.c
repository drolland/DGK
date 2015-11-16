#ifndef __NO_SDL__

#include <SDL2/SDL.h>
#include <assert.h>
#include "dtypes.h"
#include "dgkwindow.h"
#include "dmemory.h"
#include "dlogger.h"
#include "dgl.h"

boolean sdl_video_has_been_initialized = FALSE;

typedef struct _dgk_window {
    SDL_Window* sdl_window;
    SDL_GLContext* sdl_gl_context;
        
} DGK_Window;



// TODO : implements all SDL option
DGK_Window* dgk_window_create(char* title, int x, int y, int width, int height,DError** error){
    
    DLOGI("Creating SDL window");
    
            
    DGK_Window* window = NULL;
    
    if ( sdl_video_has_been_initialized == FALSE){
        if ( SDL_Init(SDL_INIT_VIDEO) < 0 ){
            if ( error)
                *error = DERROR("Can't initiliaze SDL_VIDEO, SDL ERROR !",(char*)SDL_GetError());
            goto error;
        }
        sdl_video_has_been_initialized = TRUE;
    }
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    window = d_malloc(sizeof(DGK_Window));
    window->sdl_window = NULL;
    window->sdl_gl_context = NULL;
    
    window->sdl_window = SDL_CreateWindow(title,x,y,width,height,SDL_WINDOW_OPENGL);
    
       
    if ( window->sdl_window == NULL){
        if (error)
            *error = DERROR("Can't create SDL window, SDL Error : %s",SDL_GetError());
        goto error;
    }
    
    int win_w;
    int win_h;
    SDL_GetWindowSize(window->sdl_window,&win_w,&win_h);
    
    DLOGI("Window created with width : %d and height : %d",win_h,win_h);
    
    window->sdl_gl_context = SDL_GL_CreateContext(window->sdl_window);
    
    if ( window->sdl_gl_context == NULL){
        if (error)
            *error = DERROR("Can't create SDL GL context, SDL Error : %s",SDL_GetError());
        goto error;
    }
    
    DLOGI("** GL Context created **");
    int get_attr_code;
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,&get_attr_code);
    DLOGI("GL Context major version : %d",get_attr_code);
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,&get_attr_code);
    DLOGI("GL Context minor version : %d",get_attr_code);
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,&get_attr_code);
    if ( get_attr_code == SDL_GL_CONTEXT_PROFILE_CORE){
        DLOGI("GL context profile : Core");
    }
    else if ( get_attr_code == SDL_GL_CONTEXT_PROFILE_COMPATIBILITY){
        DLOGI("GL context profile : Compatibility");
    }
    else if ( get_attr_code == SDL_GL_CONTEXT_PROFILE_ES){
        DLOGI("GL context profile : ES");
    }
    int red_size;
    int blue_size;
    int green_size;
    int alpha_size;
    SDL_GL_GetAttribute(SDL_GL_RED_SIZE,&red_size);
    SDL_GL_GetAttribute(SDL_GL_GREEN_SIZE,&green_size);
    SDL_GL_GetAttribute(SDL_GL_BLUE_SIZE,&blue_size);
    SDL_GL_GetAttribute(SDL_GL_ALPHA_SIZE,&alpha_size);
    DLOGI("GL Context Color depth RGBA : %d:%d:%d:%d",red_size,green_size,blue_size,alpha_size);
    SDL_GL_GetAttribute(SDL_GL_DEPTH_SIZE,&get_attr_code);
    DLOGI("GL Context depth buffer size : %d",get_attr_code);
    SDL_GL_GetAttribute(SDL_GL_DOUBLEBUFFER,&get_attr_code);
    DLOGI("GL Context double bufferd (Yes=1,No=0) : %d",get_attr_code);
    
    dgl_init(error);    
    if (*error)
        goto error;
    
    return window;
    
    error:
    if ( window ) dgk_window_free(window);
    return NULL;
}

void dgk_window_free(DGK_Window* window){
    if ( window->sdl_gl_context) SDL_GL_DeleteContext(window->sdl_gl_context);
    if ( window->sdl_window ) SDL_DestroyWindow(window->sdl_window);
    free(window);
}

#endif