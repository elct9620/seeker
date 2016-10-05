// Copyright 2016 Zheng Xian Qiu

#pragma once

#ifndef INSTANCE_H_
#define INSTANCE_H_

#include "Seeker.h"

namespace Seeker {

  class Window;
  class Renderer;

  class Instance {
    public:
      Instance();
      ~Instance();

      Window* getWindow() { return window; }
      Renderer* getRenderer() { return renderer; }

    private:
      Window* window;
      Renderer* renderer;
  };
}

#endif
