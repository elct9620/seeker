// Copyright 2016 Zheng Xian Qiu

#include "Instance.h"

namespace Seeker {

  const int Instance::FPS = 60;
  const int Instance::FIXED_DELTA_TIME = 1000/60;

  Instance::Instance() : stop(false) {
    window = new Window;
    if(window->create(Framework::DEFAULT_WINDOW_NAME) == false) {
      // TODO: Use custom exception instead it.
      free(window);
      throw false;
    }
    renderer = window->getRenderer();

    Event::on(this);

    lastTime = currentTime();
  }

  Instance::~Instance() {
    free(window);
    free(renderer);
  }

  void Instance::run() {
    while(!stop) {
      Event::refresh();
      update();
    }
  }

  void Instance::update() {
    long realTime = currentTime();

    while(lastTime < realTime) {
      lastTime += FIXED_DELTA_TIME;
      // TODO: Modify to use "GameState"
      if(currentScene) {
        currentScene->update(FIXED_DELTA_TIME);
      }
    }

    renderer->clear();
    currentScene->render();
    renderer->render();
  }

  long Instance::currentTime() {
    auto now = high_resolution_clock::now();
    auto nowInMillisecond = time_point_cast<milliseconds>(now);
    auto epoch = nowInMillisecond.time_since_epoch();
    auto value = duration_cast<milliseconds>(epoch);
    return value.count();
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

  void Instance::setScene(Scene* scene) {
    currentScene = scene;
  }
}
