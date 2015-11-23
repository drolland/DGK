#pragma once
#define GLSL(version, shader)  "#version " #version "\n" #shader
#define MULTI_LINE_STRING(...) #__VA_ARGS__


static char* gui_vert_shader = \
   "#version 100 \n" \
    MULTI_LINE_STRING (
    uniform mat4 mvp_matrix;

    attribute vec3 v_position;

    void main(){

        gl_Position = mvp_matrix * vec4(v_position,1);

    }

);


