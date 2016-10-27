// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {

  vector<ISubscriber*> Event::subscribers;

  void Event::Refresh() {
    SDL_Event ev;
    while(SDL_PollEvent(&ev)) {
      switch(ev.type) {
        case SDL_KEYDOWN:
          Dispatch(EventType::Key);
          break;
        case SDL_QUIT:
          Dispatch(EventType::Quit);
          break;
        case SDL_MOUSEBUTTONDOWN:
          Dispatch(EventType::Mouse);
          break;
      }
    }
  }

  void Event::On(ISubscriber* event) {
    if(Exists(event)) return;
    subscribers.push_back(event);
  }

  void Event::Off(ISubscriber* event) {
    if(Exists(event)) {
      subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), event), subscribers.end());
    }
  }

  bool Event::Exists(ISubscriber* event) {
    for(auto &current : subscribers) {
      if(current == event) {
        return true;
      }
    }
    return false;
  }

  void Event::Dispatch(const EventType type) {
    for(auto &current : subscribers) {
      current->OnEvent(type);
    }
  }
}
