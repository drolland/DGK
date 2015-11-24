#pragma once

#define GLSL(version, shader)  "#version " #version "\n" #shader

#define MULTI_LINE_STRING(...) #__VA_ARGS__

static char* gui_frag_shader = \
    "#version 100 \n" \
    MULTI_LINE_STRING (
        
    uniform sampler2D texture0;
    varying highp vec2 tex_coord;
    const highp vec4 color = vec4(125.5,0.5,0.5,0.5); 
    
    void main(){
    
        gl_FragColor = texture2D(texture0,tex_coord);
    
    }
    
);

