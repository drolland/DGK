#pragma once
#include "dgk_texture.h"

typedef struct _dgk_3dobject DGK3DObject;

typedef struct _dgk_sprite DGKSprite;


void dgk_3dobject_render(DGK3DObject* object);

void dgk_3dobject_set_texture(DGK3DObject* object,DGKTexture* texture);

DGKSprite* dgk_sprite_new();

void dgk_sprite_set_position(DGKSprite* sprite,float posx,float posy);

void dgk_sprite_set_size(DGKSprite* sprite,float w,float h);