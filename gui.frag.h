#pragma once

#define GLSL(version, shader)  "#version " #version "\n" #shader

#define MULTI_LINE_STRING(...) #__VA_ARGS__

char* gui_frag_shader = \
    "#version 100 \n" \
    MULTI_LINE_STRING (
        
    const highp vec4 color = vec4(125.0,0.5,0.5,0.5); 
    
    void main(){
    
        gl_FragColor = color;
    
    }
    
);

