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

      ~GameState();

      virtual void update(long delta);
      virtual void render();

      Scene* getCurrentScene();


    private:
      Scene* currentScene;
  };
}

#endif
