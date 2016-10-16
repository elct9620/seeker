// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <vector>
#include "Seeker.h"

#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

using std::vector;

namespace Seeker {
  class GameObject {
    GameObject();
    ~GameObject();

    virtual void update(int delta);
    virtual void draw() = 0;

    void addChild(GameObject* child);
    void removeChild(GameObject* child);

    protected:
    GameObject* parent;

    int x = 0;
    int y = 0;
    bool visible = true;

    private:
    vector<GameObject*> children;
  };
}

#endif
