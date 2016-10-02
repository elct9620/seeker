// Copyright 2016 Zheng Xian Qiu

#pragma once

#ifndef WINDOW_H_
#define WINDOW_H_

#include <string>
#include "Framework.h"

using std::string;

namespace Seeker {
  class Renderer;
  class Window {

    public:
      Window();
      ~Window();

      // Display Information
      static int DISPLAY_INDEX;
      static int getDisplayWidth();
      static int getDisplayHeight();

      static void loadDisplayMode(bool reload = false);

      // Window Manager
      bool create(string title, bool hide = false);
      void destroy();

      Renderer* getRenderer();

    private:
      static SDL_DisplayMode displayMode;
      static bool displayModeLoaded;
      SDL_Window *currentWindow;
      Renderer* renderer;
  };
}

#endif
