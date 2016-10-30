// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"

#ifndef GAME_STATE_H_
#define GAME_STATE_H_

namespace Seeker {
  class Scene;

  class GameState {
    public:
      GameState();
      GameState(Scene* scene);

      virtual ~GameState();

      virtual void Update(long delta);
      virtual void Render();

      Scene* CurrentScene();
      bool TransitionTo(Scene* nextScene);

    private:
      Scene* currentScene = nullptr;
      Scene* prevScene = nullptr;
  };
}

#endif
