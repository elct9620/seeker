// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <string>
#include "Seeker.h"

#ifndef WINDOW_H_
#define WINDOW_H_

using std::string;

namespace Seeker {
  class Renderer;
  class Window {

    public:
      Window();
      ~Window();

      // Display Information
      static int DISPLAY_INDEX;
      static int DisplayWidth();
      static int DisplayHeight();

      static void LoadDisplayMode(bool reload = false);

      // Window Manager
      bool Create(string title, bool hide = false);
      bool Create(string title, int _width, int _height, bool hide = false);
      void Destroy();

      Seeker::Renderer* Renderer();

    private:
      static SDL_DisplayMode displayMode;
      static bool displayModeLoaded;
      SDL_Window *currentWindow = nullptr;
      class Renderer* renderer = nullptr;
  };
}

#endif
