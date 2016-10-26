// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <vector>

#include "Seeker.h"

#ifndef SCENE_H_
#define SCENE_H_

using std::vector;
using std::unordered_map;

namespace Seeker {
  class Scene {
    public:
      Scene();
      virtual ~Scene();

      virtual void update(int delta);
      virtual void render();

      void add(GameObject* object);
      void to(Scene* scene);
      bool loaded();

    private:
      vector<GameObject*> objects = {};
  };
}

#endif
