// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <chrono>
#include "Seeker.h"

#ifndef INSTANCE_H_
#define INSTANCE_H_

using std::chrono::high_resolution_clock;
using std::chrono::time_point_cast;
using std::chrono::milliseconds;
using std::chrono::duration_cast;

namespace Seeker {

  class Window;
  class Renderer;
  class GameState;
  class Scene;

  class Instance : public ISubscriber {
    public:
      static const int FPS;
      static const int FIXED_DELTA_TIME;

      Instance();
      Instance(GameState* state);
      ~Instance();

      Window* getWindow() { return window; }
      Renderer* getRenderer() { return renderer; }

      void run();
      void update();

      long currentTime();

      virtual void onEvent(const EventType evnet);

      GameState* getState();
      GameState* setState(GameState* _state);
      Scene* getCurrentScene();

      template<class T> T* getScriptEngine() {
        return T::instance();
      }

    private:
      Window* window;
      Renderer* renderer;

      GameState* state;

      int lastTime = 0;
      bool stop = false;
  };
}

#endif
