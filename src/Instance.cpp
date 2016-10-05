// Copyright 2016 Zheng Xian Qiu

#include "Instance.h"

namespace Seeker {
  Instance::Instance() {
    window = new Window;
    if(window->create(Framework::DEFAULT_WINDOW_NAME) == false) {
      // TODO: Use custom exception instead it.
      free(window);
      throw false;
    }
    renderer = window->getRenderer();
  }

  Instance::~Instance() {

  }
}
