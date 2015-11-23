#include "dgk_3dobject.h"
#include "glad.h"
#include "d_memory.h"
#include "d_ml.h"

typedef struct _dgk_3dobject {
    void (*render)(DGK3DObject* object);
    GLuint vbo_vertex_array;
    GLuint vbo_element_array;
} DGK3DObject;

typedef struct _dgk_sprite {
    DGK3DObject object;
} DGKSprite;

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

struct sprite_mesh {
    boolean has_been_initalised;
    GLuint vbo_vertex_array;
    GLuint vbo_element_array;
} g_sprite_mesh = {FALSE, 0, 0};

void sprite_render(DGK3DObject* object) {

    glBindBuffer(GL_ARRAY_BUFFER, g_sprite_mesh.vbo_vertex_array);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, g_sprite_mesh.vbo_element_array);

    mat4 mvp;
    d_mat4_perspective(mvp, 90, 1, 1, 100);

    glUniformMatrix4fv(0, 1, GL_FALSE, (float*) mvp);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, BUFFER_OFFSET(0));


}

void sprite_init_global_mesh() {

    glGenBuffers(1, &g_sprite_mesh.vbo_vertex_array);
    glBindBuffer(GL_ARRAY_BUFFER, g_sprite_mesh.vbo_vertex_array);

    GLfloat vertex_array[] = {-1, 1, -3,
        0, 1, -3,
        0, 0, -3,
        -1, 0, -3};
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

    new_sprite->object.render = sprite_render;

    return new_sprite;

}

void dgk_3dobject_render(DGK3DObject* object) {
    object->render(object);
}