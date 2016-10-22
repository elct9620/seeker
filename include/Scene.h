// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <vector>

#include "Seeker.h"

#ifndef SCENE_H_
#define SCENE_H_

using std::vector;

namespace Seeker {
  // TODO: Refactor the update/render method to drawable interface
  class Scene {
    public:
      virtual ~Scene();

      virtual void update(int delta);
      virtual void render();

      void add(GameObject* object);

    private:
      vector<GameObject*> objects = {};
  };
}

#endif
