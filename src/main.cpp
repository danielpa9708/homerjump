#include "game.h"

void init() {
  //sprites
  pspr(background) = new Sprite();
  pspr(player    ) = new Player();
  //images
  img(background ).load("img/background.png" );
  img(grass      ).load("img/grass.png"      );
  img(homero_idle).load("img/homero_idle.png");
  img(homero_jump).load("img/homero_jump.png");
  img(homero_run ).load("img/homero_run.png" );
  //animations           image             www  hhh  f fo speed loop
  anim(background) =  { &img(background ), 640, 480, 1, 0, 0  , false };
  anim(grass) =       { &img(grass      ), 32 , 32 , 1, 0, 0  , false };
  anim(homero_idle) = { &img(homero_idle), 32 , 70 , 2, 0, 0.1, true  };
  anim(homero_jump) = { &img(homero_jump), 44 , 68 , 4, 0, 0.2, false };
  anim(homero_run) =  { &img(homero_run ), 41 , 62 , 5, 0, 0.4, true  };
}

bool b;
void start_position() {
  b = false;
  view_x = 0;
  player().vs = 0;
  set_sprite(spr(player), &anim(homero_run), room_width/2, room_height, 29, 64);
  srand(0);
  field.random(0, roomt_width+1, 5);
}

void start() {
  init();
  keyboard = get_keyboard_state();
  set_sprite(spr(background), &anim(background), 0, 0, room_width, room_height);
  start_position();
}
void step() {
  input();
  if(b) {
    return;
  }
  int xx1, xx2;
  xx1 = view_x/tile_width;
  view_x += view_speed;
  xx2 = view_x/tile_width;
  if(xx1 < xx2) {
    xx2 = (xx1-1+roomt_width)%roomt_width;
    field.random(xx1, field.arr[xx2]);
  }
  if(view_x >= room_width+tile_width) {
    view_x -= room_width+tile_width;
  }
  spr(player).update();

  if(spr(player).x < view_x) {
    if(spr(player).x + view_speed >= view_x) {
      b = true;
    }
  }
}

void draw() {
  draw_xos = 0;
  spr(background).draw();
  draw_xos = view_x;
  field.draw();
  spr(player).draw();
}

void end() {
  for(auto spr: sprites)
    delete spr;
}
