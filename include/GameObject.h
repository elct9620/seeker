// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <vector>
#include "Seeker.h"

#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

using std::vector;

namespace Seeker {
  // TODO: Refactor the update/render method to drawable interface
  class GameObject {
    public:
      GameObject();
      GameObject(int x, int y) : x(x), y(y) {} ;
      virtual ~GameObject();

      virtual void update(int delta);
      virtual void render();

      virtual void draw() = 0;

      void addChild(GameObject* child);
      void removeChild(GameObject* child);

      int setX(int _x);
      int setY(int _y);
      int getX();
      int getY();

    protected:
      GameObject* parent = nullptr;

      int x = 0;
      int y = 0;
      bool visible = true;

    private:
      vector<GameObject*> children = {};
  };
}

#endif
