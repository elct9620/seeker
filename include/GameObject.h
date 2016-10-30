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

      virtual void Update(int delta);
      virtual void Render();

      virtual void Draw() = 0;

      void AddChild(GameObject* child);
      void RemoveChild(GameObject* child);

      int SetX(int _x);
      int SetY(int _y);
      int X();
      int Y();

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
