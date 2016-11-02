// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  Actor::Actor(const string &filename) {
    Actor(filename, 0, 0);
  }

  Actor::Actor(const string &filename, int x, int y) : GameObject(x, y) {
    sprite = new Sprite(filename);
  }

  Actor::~Actor() {
    delete sprite;
  }

  void Actor::Draw() {
    int drawX = 0, drawY = 0;

    if(parent) {
      drawX = parent->X();
      drawY = parent->Y();
    }

    drawX += _x;
    drawY += _y;

    sprite->Draw(drawX, drawY);
  }
}
