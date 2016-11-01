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
      GameObject(int x, int y) : _x(x), _y(y) {} ;
      virtual ~GameObject();

      virtual void Update(int delta);
      virtual void Render();

      virtual void Draw() = 0;

      void AddChild(GameObject* child);
      void RemoveChild(GameObject* child);

      int SetX(int _x);
      int SetY(int _y);
      int SetZ(int _z);
      int X();
      int Y();
      int Z();

      int ZIndex();
      int ZIndex(int _z);

      static bool ZOrderCompare(GameObject* a, GameObject* b) {
        return a->ZIndex() > b->ZIndex();
      };
    protected:
      GameObject* parent = nullptr;

      int _x = 0;
      int _y = 0;
      int _z = 0;
      bool visible = true;

      void ReSortChildren();

    private:
      vector<GameObject*> children = {};
  };
}

#endif
