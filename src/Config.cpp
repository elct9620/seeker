// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  Config::WindowSetting Config::Window = {
    // Name
    Framework::DEFAULT_WINDOW_NAME,
    // Width
    Window::getDisplayWidth(),
    // Height
    Window::getDisplayHeight()
  };
}
