#include "dgk_3dobject.h"
#include "glad.h"
#include "d_memory.h"
#include "d_ml.h"
#include "dgk_shader.h"


typedef struct _dgk_3dobject {
    void (*render)(DGK3DObject* object);
    DGKShader* shader;
    DGKTexture* texture0;
    GLuint vbo_vertex_array;
    GLuint vbo_element_array;
} DGK3DObject;

typedef struct _dgk_sprite {
    DGK3DObject object;
    float posx;
    float posy;
    float w;
    float h;
} DGKSprite;

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

struct sprite_mesh {
    boolean has_been_initalised;
    GLuint vbo_vertex_array;
    GLuint vbo_element_array;
} g_sprite_mesh = {FALSE, 0, 0};

void dgk_3dobject_render(DGK3DObject* object) {
    dgk_shader_bind(object->shader);
    object->render(object);
}

void dgk_3dobject_set_texture(DGK3DObject* object, DGKTexture* texture){
    object->texture0 = texture;    
}


void sprite_render(DGK3DObject* object) {

    glBindBuffer(GL_ARRAY_BUFFER, g_sprite_mesh.vbo_vertex_array);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, g_sprite_mesh.vbo_element_array);

    DGKSprite* sprite = (DGKSprite*)object;
    
    mat4 mvp = { 2 * ( sprite->w),0,0,0,
                 0,2*(sprite->h),0,0,
                 0,0,0,0,
                 -1 + 2 * sprite->posx, 1 - 2 * sprite->posy,0,1 };
    

    glUniformMatrix4fv(0, 1, GL_FALSE, (float*) mvp);
    

    glActiveTexture(GL_TEXTURE0);
    dgk_texture_bind(object->texture0);
    glUniform1i(1, 0);

    
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), BUFFER_OFFSET(0));
    

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), BUFFER_OFFSET(3 * sizeof(GLfloat)));


    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, BUFFER_OFFSET(0));


}

void sprite_init_global_mesh() {

    glGenBuffers(1, &g_sprite_mesh.vbo_vertex_array);
    glBindBuffer(GL_ARRAY_BUFFER, g_sprite_mesh.vbo_vertex_array);

    GLfloat vertex_array[] = {0, 0, 0, 0 , 0,
        1, 0, 0, 1 , 0,
        1, -1, 0, 1 , 1,
        0, -1, 0 , 0 , 1} ;
    glBufferData(GL_ARRAY_BUFFER, sizeof (vertex_array), vertex_array, GL_STATIC_DRAW);

    glGenBuffers(1, &g_sprite_mesh.vbo_element_array);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, g_sprite_mesh.vbo_element_array);

    GLushort element_array[] = {0, 3, 2, 0, 2, 1};
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof (element_array), element_array, GL_STATIC_DRAW);

    g_sprite_mesh.has_been_initalised = TRUE;

}


DGKSprite* dgk_sprite_new() {

    if (g_sprite_mesh.has_been_initalised == FALSE)
        sprite_init_global_mesh();

    DGKSprite* new_sprite = d_malloc(sizeof (DGKSprite));

    new_sprite->posx = 0;
    new_sprite->posy = 0;
    new_sprite->w = 0;
    new_sprite->h = 0;
    
    new_sprite->object.render = sprite_render;
    new_sprite->object.shader = dgk_shader_pool_get_builtin_shader(DGKSHADER_BUILTIN_SPRITE);
       
    return new_sprite;
}

void dgk_sprite_set_position(DGKSprite* sprite, float posx, float posy){
    sprite->posx = posx;
    sprite->posy = posy;
}

void dgk_sprite_set_size(DGKSprite* sprite, float w, float h){
    sprite->w = w;
    sprite->h = h;
}
