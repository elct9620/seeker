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

  void GameState::Update(long delta) {
    if(currentScene) {
      currentScene->Update(delta);
    }
  }

  void GameState::Render() {
    if(currentScene) {
      currentScene->Render();
    }

    if(UI) {
      UI->Draw();
    }
  }

  Scene* GameState::CurrentScene() {
    return currentScene;
  }

  bool GameState::TransitionTo(Scene* _next) {
    if(!_next) {
      return false;
      Logger::Error("Next scene is not exists!");
    }

    if(prevScene) {
      delete prevScene;
      prevScene = NULL;
    }

    while(!_next->Loaded()) {
      // Wait resource loaded
    }
    prevScene = currentScene;
    currentScene = _next;

    return true;
  }

  void GameState::SetUI(UI::Widget* widget) {
    if(UI) {
      delete UI;
    }
    UI = widget;
  }
}
