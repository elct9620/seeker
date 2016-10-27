// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  Actor::Actor(const string &filename) {
    sprite = Resource<Sprite>::Load(filename);
  }

  Actor::Actor(const string &filename, int x, int y) : GameObject(x, y) {
    sprite = Resource<Sprite>::Load(filename);
  }

  Actor::~Actor() {
    sprite->Destroy();
  }

  void Actor::Draw() {
    int drawX = 0, drawY = 0;

    if(parent) {
      drawX = parent->X();
      drawY = parent->Y();
    }

    drawX += x;
    drawY += y;

    sprite->Draw(x, y);
  }
}
