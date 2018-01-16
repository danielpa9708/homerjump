#include "map.h"
#include "game.h"
#include <cstdio>

Map::Map() {
  set_sprite(size, &anim(grass), 0, 0, tile_width, tile_width);
  size.frame = 0;
}

int Map::lowest(int i, int j) {
  if(i >= width) {
    i -= width;
    j -= width;
  }
  int index = i;
  for(i++; i <= j; i++) {
    if(i >= width) {
      i -= width;
      j -= width;
    }
    if(arr[i] < arr[index]) {
      index = i;
    }
  }
  return index;
}
int Map::highest(int i, int j) {
  if(i >= width) {
    i -= width;
    j -= width;
  }
  int index = i;
  for(i++; i <= j; i++) {
    if(i >= width) {
      i -= width;
      j -= width;
    }
    if(arr[i] < arr[index]) {
      index = i;
    }
  }
  return index;
}

void Map::draw() {
  int i, j;
  for(i = 0; i < width; i++) {
    j = arr[i];
    size.x = i * size.width;
    for(j; j < height; j++) {
      size.y = j * size.height;
      size.draw();
    }
    j = arr[i];
    size.x += room_width+tile_width;
    for(j; j < height; j++) {
      size.y = j * size.height;
      size.draw();
    }
  }
}

void Map::random(int i, int j, int r) {
  for(i; i < j; i++) {
    r = ((rand()%3)-1) + r;
    if(r < min) r = min;
    else if(r > max) r = max;
    arr[i] = r;
  }
}

void Map::random(int i, int r) {
  r = ((rand()%3)-1) + r;
  if(r < min) r = min;
  else if(r > max) r = max;
  arr[i] = r;
}
