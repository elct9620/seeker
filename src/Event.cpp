// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {

  vector<ISubscriber*> Event::subscribers;

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

  void Event::on(ISubscriber* event) {
    if(exists(event)) return;
    subscribers.push_back(event);
  }

  void Event::off(ISubscriber* event) {
    if(exists(event)) {
      subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), event), subscribers.end());
    }
  }

  bool Event::exists(ISubscriber* event) {
    for(auto &current : subscribers) {
      if(current == event) {
        return true;
      }
    }
    return false;
  }

  void Event::dispatch(const EventType type) {
    for(auto &current : subscribers) {
      current->onEvent(type);
    }
  }
}
