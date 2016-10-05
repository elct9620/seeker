// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {

  vector<IEvent*> Event::events;

  void Event::refresh() {
    SDL_Event ev;
    while(SDL_PollEvent(&ev)) {
      switch(ev.type) {
        case SDL_KEYDOWN:
          dispatch(EventType::Key);
          break;
        case SDL_QUIT:
          dispatch(EventType::Quit);
          break;
        case SDL_MOUSEBUTTONDOWN:
          dispatch(EventType::Mouse);
          break;
      }
    }
  }

  void Event::on(IEvent* event) {
    if(exists(event)) return;
    events.push_back(event);
  }

  void Event::off(IEvent* event) {
    if(exists(event)) {
      events.erase(std::remove(events.begin(), events.end(), event), events.end());
    }
  }

  bool Event::exists(IEvent* event) {
    for(auto &current : events) {
      if(current == event) {
        return true;
      }
    }
    return false;
  }

  void Event::dispatch(const EventType type) {
    for(auto &current : events) {
      current->onEvent(type);
    }
  }
}
