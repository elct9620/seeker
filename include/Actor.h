// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"

#ifndef ACTOR_H_
#define ACTOR_H_

namespace Seeker {
  class Actor : public GameObject {
    public:
      Actor(Sprite* sprite) : sprite(sprite) {};
      Actor(Sprite* sprite, int x, int y) : GameObject(x, y), sprite(sprite) {};
      Actor(const string &filename);
      Actor(const string &filename, int x, int y);
      virtual ~Actor();

      virtual void Draw();

    private:
      Sprite* sprite = nullptr;
  };
}

#endif
