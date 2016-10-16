// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {

  vector<GameObject*> children;

  GameObject::GameObject() : x(0), y(0) {
  }

  GameObject::~GameObject() {

  }

  void GameObject::update(int delta) {
    for(const auto &child : children) {
      child->update(delta);
    }

    draw();
  }

  void GameObject::addChild(GameObject* child) {
    if(std::find(children.begin(), children.end(), child) != children.end()) {
      return;
    }

    child->parent = this;
    children.push_back(child);
  }

  void GameObject::removeChild(GameObject* child) {
    vector<GameObject*>::iterator it = std::find(children.begin(), children.end(), child);
    if(it == children.end()) {
      return;
    }

    child->parent = nullptr;
    children.erase(it);
  }
}
