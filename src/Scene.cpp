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
  void Scene::Update(int delta) {
    for(auto it : objects) {
      it->Update(delta);
    }
  }

  void Scene::Render() {
    for(auto it : objects) {
      it->Render();
    }
  }

  void Scene::Add(GameObject* object) {
    objects.push_back(object);
  }

  bool Scene::Loaded() {
    // TODO: Check all children assets is loaded
    return true;
  }

  void Scene::To(Scene* scene) {
    Framework::Game()->State()->TransitionTo(scene);
  }

}
