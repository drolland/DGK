#pragma once

#include "d_error.h"

typedef struct _dgk_shader DGKShader;

typedef struct _dgk_shader_pool DGKShaderPool;

enum {
    DGKSHADER_BUILTIN_SPRITE,
    DGKSHADER_BUILTIN_TOTAL
};

DGKShaderPool* dgk_shader_pool_get_instance();

DGKShader* dgk_shader_pool_get_builtin_shader(DGKShaderPool* pool, int shader);

DGKShader* dgk_shader_load(const char* vert_shader_source,const char* frag_shader_source,DError** error);

void dgk_shader_bind(DGKShader* shader);

void dgk_shader_free(DGKShader* shader);

