// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"

#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

namespace Seeker {
  class Window;
  class Renderer;

  class Framework {
    public:
      static Framework* getInstance();
      static void quit();

      static string DEFAULT_WINDOW_NAME;

      inline void use(Window* window) { currentWindow = window; };
      inline void use(Renderer* renderer) { currentRenderer = renderer; };

      Renderer* getRenderer();
      Window* getWindow();

      void bootstrap();

    private:
      static Framework* instance;

      Framework();
      ~Framework();

      Window* currentWindow;
      Renderer* currentRenderer;
  };
}

#endif
