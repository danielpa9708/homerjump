#ifndef GAME_H
#define GAME_H

#include "common.h"
#include "player.h"
#include "map.h"

#define img(name) (images[img_##name])
#define anim(name) (animations[anim_##name])
#define pspr(name) (sprites[spr_##name])
#define spr(name) (*pspr(name))
#define convert(var, type) ((type)(var))
#define pplayer() (convert(pspr(player), Player*))
#define player() (*(pplayer()))
#define set_sprite(spr, anim, vx, vy, vw, vh)   \
  spr.set_animation(anim);                      \
  spr.x = vx; spr.y = vy;                       \
  spr.width = vw; spr.height = vh;

#define img_num 5
enum img_index {
  img_background,
  img_grass,
  img_homero_idle,
  img_homero_jump,
  img_homero_run,
};
#define anim_num 5
enum anim_index {
  anim_background,
  anim_grass,
  anim_homero_idle,
  anim_homero_jump,
  anim_homero_run,
};
#define spr_num 2
enum spr_index {
  spr_background,
  spr_player,
};

extern Image images[img_num];
extern Animation animations[anim_num];
extern Sprite *sprites[spr_num];
extern bool * keyboard;
extern int view_x;
extern Map field;

void input();

void start_position();

#endif
