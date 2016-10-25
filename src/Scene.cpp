// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  Scene::Scene(const string& name) : name(name) {
  }

  Scene::~Scene() {
    for(auto it : objects) {
      delete it;
    }
    objects.clear();

    auto it = scenes.find(name);
    if(it != scenes.end()) {
      scenes.erase(it);
    }
  }

  // Class Method
  unordered_map<string, Scene*> Scene::scenes = {};

  Scene* Scene::create(const string& name) {
    auto it = scenes.find(name);
    if(it != scenes.end()) {
      return (*it).second;
    }

    Scene* scene = new Scene(name);
    scenes.insert(std::pair<string, Scene*>(name, scene));
    return scene;
  }

  Scene* Scene::get(const string& name) {
    auto it = scenes.find(name);
    if(it != scenes.end()) {
      return (*it).second;
    }
    return nullptr;
  }

  int Scene::count() {
    return scenes.size();
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

  string Scene::getName() {
    return name;
  }

  void Scene::to(Scene* scene) {
    Framework::getInstance()->getGameInstance()->getState()->transitionTo(scene);
  }

}
