// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  Scene::Scene() {
  }

  Scene::~Scene() {
    for(auto it : objects) {
      delete it;
    }
    objects.clear();
  }
  // Instance Method
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

  bool Scene::loaded() {
    // TODO: Check all children assets is loaded
    return true;
  }

  void Scene::to(Scene* scene) {
    Framework::getInstance()->getGameInstance()->getState()->transitionTo(scene);
  }

}
