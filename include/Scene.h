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
      virtual ~Scene();

      static Scene* create(const string& name);
      static Scene* get(const string& name);
      static int count();

      virtual void update(int delta);
      virtual void render();

      void add(GameObject* object);
      void to(Scene* scene);
      bool loaded();
      string getName();

    private:
      Scene(const string& name);

      static unordered_map<string, Scene*> scenes;

      vector<GameObject*> objects = {};
      string name = "";
  };
}

#endif
