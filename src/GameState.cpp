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

  bool GameState::transitionTo(Scene* _next) {
    // TODO: Prevent delete script's scene
    if(nextScene) delete nextScene;
    if(prevScene) delete prevScene;

    prevScene = currentScene;

    // TODO: Let scene transition wait scene resource loaded
    nextScene = _next;
    currentScene = nextScene;

    return true;
  }
}
