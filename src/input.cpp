#include "game.h"

bool * keyboard;

void input() {
  Player &player = player();
  if(keyboard[VKEY(UP)]) {
    player.jump();
  }
  if(keyboard[VKEY(F2)]) {
    start_position();
  }
  if(keyboard[VKEY(RETURN)]) {
    set_fullscreen(!is_fullscreen());
  }
}
