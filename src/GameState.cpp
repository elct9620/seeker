// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  GameState::GameState() {

  }

  GameState::GameState(Scene* scene) : currentScene(scene) {
  }

  GameState::~GameState() {
    // TODO: release "currentScene"
    delete prevScene;
    delete currentScene;
    delete prevScene;
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
    if(!_next) {
      return false;
      Logger::Error("Next scene is not exists!");
    }

    if(prevScene) {
      delete prevScene;
      prevScene = NULL;
    }

    while(!_next->loaded()) {
      // Wait resource loaded
    }
    prevScene = currentScene;
    currentScene = _next;

    return true;
  }
}
