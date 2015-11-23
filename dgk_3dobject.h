#pragma once

typedef struct _dgk_3dobject DGK3DObject;

typedef struct _dgk_sprite DGKSprite;

DGKSprite* dgk_sprite_new();

void dgk_3dobject_render(DGK3DObject* object);