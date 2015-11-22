#pragma once

#include "derror.h"

typedef struct _dgk_shader DGKShader;

DGKShader* dgk_shader_load(const char* vert_shader_source,const char* frag_shader_source,DError** error);

void dgk_shader_bind(DGKShader* shader);

void dgk_shader_free(DGKShader* shader);

