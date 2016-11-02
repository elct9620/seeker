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

    EventManager::On(this);

    nextTime = CurrentTime();
  }

  Instance::~Instance() {
    delete window;
  }

  void Instance::Run() {
    while(!stop) {
      EventManager::Refresh();
      Update();
    }
  }

  void Instance::Update() {
    long realTime = CurrentTime();

    while(nextTime < realTime) {
      int deltaTime = realTime - lastTime;
      nextTime += FIXED_DELTA_TIME;
      // TODO: Modify to use "GameState"
      if(state) {
        state->Update(deltaTime);
        IScript::UpdateAll(deltaTime);

        renderer->Clear();
        state->Render();
        IScript::RenderAll();
        renderer->Render();
      }

      realFPS = 1 / ((float) deltaTime / 1000);
      lastTime = realTime;
    }
  }

  long Instance::CurrentTime() {
    auto now = high_resolution_clock::now();
    auto nowInMillisecond = time_point_cast<milliseconds>(now);
    auto epoch = nowInMillisecond.time_since_epoch();
    auto value = duration_cast<milliseconds>(epoch);
    return value.count();
  }

  // ISubscriber implement
  void Instance::OnEvent(const EventType type, Event& event) {
    switch(type) {
      case EventType::Quit:
        stop = true;
        break;
      case EventType::Mouse:
        if(static_cast<MouseEvent&>(event).button == MouseEvent::Button::Right) {
          stop = true;
        }
      default:
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
