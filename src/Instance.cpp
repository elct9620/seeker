// Copyright 2016 Zheng Xian Qiu

#include "Instance.h"

namespace Seeker {

  const int Instance::FPS = 60;
  const int Instance::FIXED_DELTA_TIME = 1000/60;

  Instance::Instance() : Instance(new GameState(new Scene())) {
  }

  Instance::Instance(GameState* state) : state(state), stop(false) {
    window = new Window;
    if(window->create(Config::Window.name, Config::Window.width, Config::Window.height) == false) {
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
      if(state) {
        state->update(FIXED_DELTA_TIME);
        IScript::updateAll(FIXED_DELTA_TIME);
      }
    }

    renderer->clear();
    state->render();
    IScript::renderAll();
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

  GameState* Instance::getState() {
    return state;
  }

  GameState* Instance::setState(GameState* _state) {
    state = _state;
    return state;
  }

  Scene* Instance::getCurrentScene() {
    return state->getCurrentScene();
  }
}
