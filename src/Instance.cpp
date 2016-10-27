// Copyright 2016 Zheng Xian Qiu

#include "Instance.h"

namespace Seeker {

  const int Instance::FPS = 60;
  const int Instance::FIXED_DELTA_TIME = 1000/60;

  Instance::Instance() : Instance(new GameState()) {
  }

  Instance::Instance(GameState* state) : state(state), stop(false) {
    window = new class Window;
    if(window->Create(Config::Window.Name, Config::Window.Width, Config::Window.Height) == false) {
      // TODO: Use custom exception instead it.
      delete window;
      throw false;
    }
    renderer = window->Renderer();

    Event::On(this);

    lastTime = CurrentTime();
  }

  Instance::~Instance() {
    delete window;
  }

  void Instance::Run() {
    while(!stop) {
      Event::Refresh();
      Update();
    }
  }

  void Instance::Update() {
    long realTime = CurrentTime();

    while(lastTime < realTime) {
      lastTime += FIXED_DELTA_TIME;
      // TODO: Modify to use "GameState"
      if(state) {
        state->Update(FIXED_DELTA_TIME);
        IScript::UpdateAll(FIXED_DELTA_TIME);
      }
    }

    renderer->Clear();
    state->Render();
    IScript::RenderAll();
    renderer->Render();
  }

  long Instance::CurrentTime() {
    auto now = high_resolution_clock::now();
    auto nowInMillisecond = time_point_cast<milliseconds>(now);
    auto epoch = nowInMillisecond.time_since_epoch();
    auto value = duration_cast<milliseconds>(epoch);
    return value.count();
  }

  // ISubscriber implement
  void Instance::OnEvent(const EventType type) {
    switch(type) {
      case EventType::Key:
      case EventType::Quit:
      case EventType::Mouse:
        stop = true;
        break;
    }
  }

  GameState* Instance::State() {
    return state;
  }

  GameState* Instance::SetState(GameState* _state) {
    state = _state;
    return state;
  }

  Scene* Instance::CurrentScene() {
    return state->CurrentScene();
  }
}
