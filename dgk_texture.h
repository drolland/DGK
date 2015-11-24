#pragma once
#include "d_error.h"

typedef struct _dgk_texture DGKTexture;

DGKTexture* dgk_texture_load_from_bmp_file(char* filepath,DError **error);

void dgk_texture_free(DGKTexture* texture);

void dgk_texture_bind(DGKTexture* texture);

