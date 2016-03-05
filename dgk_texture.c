#include "dgk_texture.h"
#include "dgk_gl.h"
#include "d_img.h"
#include "d_memory.h"
#include <assert.h>

typedef struct _dgk_texture {
    GLuint gl_texture; 
} DGKTexture;

DGKTexture* dgk_texture_load_from_bmp_file(char* filepath, DError** error){
    
    DImg* img = d_img_load_from_bmp_file(filepath,error);
    if ( *error ){
        assert(img == NULL);
        return NULL;
    }
    
    DGKTexture* texture = d_malloc(sizeof(DGKTexture));
    
    glGenTextures(1,&texture->gl_texture);
    if ( texture->gl_texture == 0){
        if ( error)
            *error = DERROR("Could not genereate OpenGL texture");
        goto error;
    }
    
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture->gl_texture);
    
    if ( img->color_format = DIMG_COLOR_FORMAT_RGB)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB,GL_UNSIGNED_BYTE, img->pixels);
    else if ( img->color_format = DIMG_COLOR_FORMAT_RGBA )
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img->width, img->height, 0, GL_RGBA,GL_UNSIGNED_BYTE, img->pixels);
    else
        assert(FALSE);
    
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    
    if ( img ) d_img_free(img);
    
    return texture;    
    
    
    error:
    if ( texture ) free(texture);
    if ( img ) d_img_free(img);
    return NULL;
    
}

void dgk_texture_bind(DGKTexture* texture){
    glBindTexture(GL_TEXTURE_2D,texture->gl_texture);
}

void dgk_texture_free(DGKTexture* texture){
    glDeleteTextures(1,&texture->gl_texture);
    if ( texture ) free(texture);
}
