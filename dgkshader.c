#include "dgkshader.h"
#include "glad.h"
#include "dmemory.h"

typedef struct _dgk_shader {
    GLuint program;
    
} DGKShader;

static DGKShader* current_bind_shader = NULL;

DGKShader* dgk_shader_load(const char* vert_shader_source,const char* frag_shader_source,DError** error){
    
    DGKShader* new_shader = d_malloc(sizeof(DGKShader));
    new_shader->program = 0;
    
    GLuint vertex_shader = 0;
    GLuint fragment_shader = 0;
    
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    if ( vertex_shader == 0 ){
        if ( error ){
            *error = DERROR("Vertex shader creation failed");
            goto error;
        }
            
    }
    
    glShaderSource(vertex_shader,1,&vert_shader_source,NULL);
    
    glCompileShader(vertex_shader);
    
    GLint compile_status;
    
    glGetShaderiv(vertex_shader,GL_COMPILE_STATUS,&compile_status);
    
    if ( compile_status == GL_FALSE ){
        if ( error ){
            GLint log_length;
            glGetShaderiv(vertex_shader,GL_INFO_LOG_LENGTH,&log_length);
            GLchar* log_buffer = d_malloc(sizeof(GLchar) * log_length+1);
            glGetShaderInfoLog(vertex_shader,log_length+1,NULL,log_buffer);
            *error = DERROR("Vertex shader compilation failed : %s",log_buffer);
            free(log_buffer);
            goto error;
        }
            
    }
    
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    if ( fragment_shader == 0 ){
        if ( error ){
            *error = DERROR("Fragment shader creation failed");
            goto error;
        }
            
    }
    
    glShaderSource(fragment_shader,1,&frag_shader_source,NULL);
    
    glCompileShader(fragment_shader);
        
    glGetShaderiv(fragment_shader,GL_COMPILE_STATUS,&compile_status);
    
    if ( compile_status == GL_FALSE ){
        if ( error ){
            GLint log_length;
            glGetShaderiv(fragment_shader,GL_INFO_LOG_LENGTH,&log_length);
            GLchar* log_buffer = d_malloc(sizeof(GLchar) * log_length+1);
            glGetShaderInfoLog(fragment_shader,log_length+1,NULL,log_buffer);
            *error = DERROR("Fragment shader compilation failed : %s",log_buffer);
            free(log_buffer);
            goto error;
        }
            
    }
    
    new_shader->program = glCreateProgram();
    if ( new_shader->program == 0 ){
        if ( error ){
            *error = DERROR("Program creation failed");
            goto error;
        }
            
    }
    
    glAttachShader(new_shader->program,vertex_shader);
    glAttachShader(new_shader->program,fragment_shader);
    
    glLinkProgram(new_shader->program);
    
    GLint link_status;
    
    glGetProgramiv(new_shader->program,GL_LINK_STATUS,&link_status);
    
    if ( link_status == GL_FALSE ){
        if ( error ){
            GLint log_length;
            glGetProgramiv(new_shader->program,GL_INFO_LOG_LENGTH,&log_length);
            GLchar* log_buffer = d_malloc(sizeof(GLchar) * log_length+1);
            glGetProgramInfoLog(new_shader->program,log_length+1,NULL,log_buffer);
            *error = DERROR("Program Linking failed : %s",log_buffer);
            free(log_buffer);
            goto error;
        }
            
    }
    
    if ( vertex_shader ) glDeleteShader(vertex_shader);
    if ( fragment_shader ) glDeleteShader(fragment_shader);
    return new_shader;
    
    error:
    if ( new_shader ) dgk_shader_free(new_shader);
    if ( vertex_shader ) glDeleteShader(vertex_shader);
    if ( fragment_shader ) glDeleteShader(fragment_shader);
    return NULL; 
}

void dgk_shader_bind(DGKShader* shader){
    if ( current_bind_shader != shader)
        glUseProgram(shader->program);
}

void dgk_shader_free(DGKShader* shader){
    if ( current_bind_shader == shader)
        current_bind_shader = NULL;
    if ( shader->program ) glDeleteProgram(shader->program);
    if ( shader ) free(shader);    
}
