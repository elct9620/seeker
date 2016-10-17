// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  Actor::Actor(const string &filename) {
    sprite = Resource<Sprite>::load(filename);
  }

  Actor::Actor(const string &filename, int x, int y) : GameObject(x, y) {
    sprite = Resource<Sprite>::load(filename);
  }

  void Actor::draw() {
    int drawX = 0, drawY = 0;

    if(parent != NULL) {
      drawX = parent->getX();
      drawY = parent->getY();
    }

    drawX += x;
    drawY += y;

    sprite->draw(x, y);
  }
}
