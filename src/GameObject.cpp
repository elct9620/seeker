// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

#include<algorithm> // Prevent use C++17 std::remove

namespace Seeker {

  vector<GameObject*> children;

  GameObject::GameObject() : x(0), y(0) {
  }

  GameObject::~GameObject() {
    for(auto it : children) {
      delete it;
    }
    children.clear();
  }

  void GameObject::Update(int delta) {
    for(const auto &child : children) {
      child->Update(delta);
    }
  }

  void GameObject::Render() {
    for(const auto &child : children) {
      child->Render();
    }

    Draw();
  }

  void GameObject::AddChild(GameObject* child) {
    if(std::find(children.begin(), children.end(), child) != children.end()) {
      return;
    }

    child->parent = this;
    children.push_back(child);
  }

  void GameObject::RemoveChild(GameObject* child) {
    vector<GameObject*>::iterator it = std::find(children.begin(), children.end(), child);
    if(it == children.end()) {
      return;
    }

    child->parent = nullptr;
    children.erase(it);
  }

  int GameObject::SetX(int _x) {
    x = _x;
    return x;
  }

  int GameObject::SetY(int _y) {
    y = _y;
    return y;
  }

  int GameObject::X() {
    return x;
  }

  int GameObject::Y() {
    return y;
  }
}
