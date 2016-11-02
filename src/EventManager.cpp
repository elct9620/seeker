// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

#include<algorithm> // Prevent use C++17 std::remove

namespace Seeker {

  vector<ISubscriber*> EventManager::subscribers;

  void EventManager::Refresh() {
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

  void EventManager::On(ISubscriber* event) {
    if(Exists(event)) return;
    subscribers.push_back(event);
  }

  void EventManager::Off(ISubscriber* event) {
    if(Exists(event)) {
      subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), event), subscribers.end());
    }
  }

  bool EventManager::Exists(ISubscriber* event) {
    for(auto &current : subscribers) {
      if(current == event) {
        return true;
      }
    }
    return false;
  }

  void EventManager::Dispatch(const EventType type) {
    for(auto &current : subscribers) {
      current->OnEvent(type);
    }
  }
}
