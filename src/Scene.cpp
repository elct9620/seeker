// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  Scene::~Scene() {
  }

  void Scene::update(int delta) {
    for(auto it : objects) {
      it->update(delta);
    }
  }

  void Scene::render() {
    for(auto it : objects) {
      it->render();
    }
  }

  void Scene::add(GameObject* object) {
    objects.push_back(object);
  }

}
