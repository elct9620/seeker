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
      static Framework* Instance();
      static void Quit();

      static string DEFAULT_WINDOW_NAME;

      class Instance* createGame();
      class Instance* Game();

      Window*  Window();
      Renderer* Renderer();

      template<class T> T* Script() {
        return T::instance();
      }

    private:
      static Framework* instance;

      Framework();
      ~Framework();

      class Instance* currentGame;

  };
}

#endif
