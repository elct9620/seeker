// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"

#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

namespace Seeker {

  class Window;
  class Renderer;
  class Instance;

  class Framework {
    public:
      static Framework* getInstance();
      static void quit();

      static string DEFAULT_WINDOW_NAME;

      Instance* createGameInstance();

      Window*  getWindow();
      Renderer* getRenderer();

    private:
      static Framework* instance;

      Framework();
      ~Framework();

      Instance* currentGameInstance;

  };
}

#endif
