#include <SDL2/SDL.h>
#include "dtypes.h"
#include "dgkwindow.h"
#include "dmemory.h"

boolean sdl_video_has_been_initialized = FALSE;

typedef struct _dgk_window {
    SDL_Window* sdl_window;
    SDL_Surface* sdl_surface;
    
} DGK_Window;

// TODO : implements all SDL option
DGK_Window* dgk_window_create(char* title, int x, int y, int width, int height){
    
    if ( sdl_video_has_been_initialized == FALSE){
        SDL_Init(SDL_INIT_VIDEO);
        sdl_video_has_been_initialized = TRUE;
    }
    
    DGK_Window* window = d_malloc(sizeof(DGK_Window));
    
    window->sdl_window = SDL_CreateWindow(title,x,y,width,height,SDL_WINDOW_OPENGL );
    window->sdl_surface = SDL_GetWindowSurface(window->sdl_window);
 
}

void dgk_window_free(DGK_Window* window){
    SDL_FreeSurface(window->sdl_surface);
    SDL_DestroyWindow(window->sdl_window);
    free(window);
}

void dgk_window_blit_image(DGK_Window* window, DImg* image,int x,int y){
    int depth;
    if ( image->color_format == DIMG_COLOR_FORMAT_RGB)
        depth = 24;
    else
        depth = 32;
    
    SDL_Surface* img_surf;
    img_surf = SDL_CreateRGBSurfaceFrom(image->pixels,image->width,image->height,depth,image->pitch,0x000000FF,0x0000FF00,0x00FF0000,0xFF000000);
    
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = 0;
    r.h = 0;
    SDL_BlitSurface(img_surf,NULL,window->sdl_surface,&r);
    SDL_UpdateWindowSurface(window->sdl_window);
    SDL_FreeSurface(img_surf);
}