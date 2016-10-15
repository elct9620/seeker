// Copyright 2016 Zheng Xian Qiu

#pragma once

#ifndef INSTANCE_H_
#define INSTANCE_H_

#include "Seeker.h"

namespace Seeker {

  class Window;
  class Renderer;

  class Instance : public ISubscriber {
    public:
      Instance();
      ~Instance();

      Window* getWindow() { return window; }
      Renderer* getRenderer() { return renderer; }

      void run();
      void update();

      virtual void onEvent(const EventType evnet);

    private:
      Window* window;
      Renderer* renderer;

      bool stop;
  };
}

#endif
