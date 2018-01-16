#include "player.h"
#include "game.h"


void Player::update() {
  move();
  fall();

  Sprite::update();

  if(x > room_width+tile_width) x = 0;
}

double Player::collide() {
  double high = y + height;
  int temp = field.lowest(x/tile_width, (x+width)/tile_width);
  temp = field.arr[temp]*tile_height;
  if(temp < high) high = temp;
  return high-height;
}

void Player::jump() {
  if(!falling) {
    vs -= jumpsp;
  }
}

void Player::move() {
  x += view_speed;
  double tmp = collide();
  if(tmp + 0.000001 < y) {
    x -= view_speed;
    running = false;
  } else {
    running = true;
  }
}

void Player::fall() {
  vs += gravity;
  y += vs;
  double temp = collide();
  if(temp + 0.000001 < y) {
    y = temp;
    vs = 0;
    falling = false;
  } else {
    falling = true;
  }

  if(falling) {
    set_animation(&anim(homero_jump));
  } else if(running) {
    set_animation(&anim(homero_run));
  } else {
    set_animation(&anim(homero_idle));
  }
}

void Player::set_animation(Animation * anim) {
  if(animation != anim) {
    Sprite::set_animation(anim);
  }
}

void Player::draw() {
  x += room_width + tile_width;
  Sprite::draw();
  x -= room_width + tile_width;
  Sprite::draw();
}
