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
      virtual ~Instance();

      Seeker::Window* Window() { return window; }
      Seeker::Renderer* Renderer() { return renderer; }

      void Run();
      void Update();

      long CurrentTime();
      float GetFPS() { return realFPS; }

      virtual void OnEvent(const EventType evnet);

      GameState* State();
      GameState* SetState(GameState* _state);
      Scene* CurrentScene();

      template<class T> T* Script() {
        return T::instance();
      }

    private:
      class Window* window = nullptr;
      class Renderer* renderer = nullptr;

      GameState* state = nullptr;

      int lastTime = 0;
      int nextTime = 0;
      float realFPS = 0;
      bool stop = false;
  };
}

#endif
