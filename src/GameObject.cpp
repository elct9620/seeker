// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

#include<algorithm> // Prevent use C++17 std::remove

namespace Seeker {

  vector<GameObject*> children;

  GameObject::GameObject() : _x(0), _y(0), _z(0) {
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

    ReSortChildren();
  }

  void GameObject::RemoveChild(GameObject* child) {
    vector<GameObject*>::iterator it = std::find(children.begin(), children.end(), child);
    if(it == children.end()) {
      return;
    }

    child->parent = nullptr;
    children.erase(it);
  }

  void GameObject::ReSortChildren() {
    std::sort(children.begin(), children.end(), ZOrderCompare);
  }

  int GameObject::SetX(int x) {
    _x = x;
    return _x;
  }

  int GameObject::SetY(int y) {
    _y = y;
    return _y;
  }

  int GameObject::SetZ(int z) {
    _z = z;
    if(parent) {
      parent->ReSortChildren();
    }
    return _z;
  }

  int GameObject::X() {
    return _x;
  }

  int GameObject::Y() {
    return _y;
  }

  int GameObject::Z() {
    return _z;
  }

  int GameObject::ZIndex() {
    return Z();
  }

  int GameObject::ZIndex(int z) {
    return SetZ(z);
  }
}
