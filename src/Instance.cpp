// Copyright 2016 Zheng Xian Qiu

#include "Instance.h"

namespace Seeker {
  Instance::Instance() : stop(false) {
    window = new Window;
    if(window->create(Framework::DEFAULT_WINDOW_NAME) == false) {
      // TODO: Use custom exception instead it.
      free(window);
      throw false;
    }
    renderer = window->getRenderer();

    Event::on(this);
  }

  Instance::~Instance() {
    free(window);
    free(renderer);
  }

  void Instance::run() {
    while(!stop) {
      Event::refresh();
    }
  }

  void Instance::update() {
    // TODO: Run update
  }

  // ISubscriber implement
  void Instance::onEvent(const EventType type) {
    switch(type) {
      case EventType::Key:
      case EventType::Quit:
      case EventType::Mouse:
        stop = true;
        break;
    }
  }
}
