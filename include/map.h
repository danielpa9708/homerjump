#ifndef MAP_H
#define MAP_H

#include "common.h"

class Map {
  const int min = 3;
  const int max = 12;
  const int width = roomt_width+1;
  const int height = roomt_height;
 public:
  Sprite size;
  int arr[roomt_width+1];
  int lowest(int i, int j);
  int highest(int i, int j);
  void random(int i, int j, int r);
  void random(int i, int r);
  void draw();
  Map();
};

#endif
