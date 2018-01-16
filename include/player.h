#ifndef PLAYER_H
#define PLAYER_H

#include "common.h"

class Player : public Sprite{
 public:
  const double speed = 4;
  const double jumpsp = 12;
  const double gravity = 1;
  double vs;
  bool falling;
  bool running;

  void update();
  double collide();
  void set_animation(Animation * anim);
  void move();
  void fall();
  void jump();

  void draw();
};

#endif
