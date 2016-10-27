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

      virtual void Update(int delta);
      virtual void Render();

      void Add(GameObject* object);
      void To(Scene* scene);
      bool Loaded();

    private:
      vector<GameObject*> objects = {};
  };
}

#endif
