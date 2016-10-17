// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  GameState::GameState() {

  }

  GameState::GameState(Scene* scene) : currentScene(scene) {
  }

  GameState::~GameState() {
    // TODO: release "currentScene"
  }

  void GameState::update(long delta) {
    if(currentScene) {
      currentScene->update(delta);
    }
  }

  void GameState::render() {
    if(currentScene) {
      currentScene->render();
    }
  }

  Scene* GameState::getCurrentScene() {
    return currentScene;
  }
}
