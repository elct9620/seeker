// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

#include<algorithm> // Prevent use C++17 std::remove

namespace Seeker {

  vector<ISubscriber*> EventManager::subscribers;

  void EventManager::Refresh() {
    SDL_Event ev;
    Event emptyEv;
    while(SDL_PollEvent(&ev)) {
      switch(ev.type) {
        case SDL_KEYDOWN:
          Dispatch(EventType::Key, emptyEv);
          break;
        case SDL_QUIT:
          Dispatch(EventType::Quit, emptyEv);
          break;
        case SDL_MOUSEBUTTONDOWN:
          MouseEvent mouseEv = CreateMouseEvent(ev);
          Dispatch(EventType::Mouse, mouseEv);
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

  void EventManager::Dispatch(const EventType type, Event& event) {
    for(auto &current : subscribers) {
      current->OnEvent(type, event);
    }
  }

  // Event Creator
  const MouseEvent EventManager::CreateMouseEvent(SDL_Event ev) {
    MouseEvent::Button btn;
    switch(ev.button.button) {
      case SDL_BUTTON_LEFT:
        btn = MouseEvent::Button::Left;
        break;
      case SDL_BUTTON_MIDDLE:
        btn = MouseEvent::Button::Middle;
        break;
      case SDL_BUTTON_RIGHT:
        btn = MouseEvent::Button::Right;
        break;
    }
    return MouseEvent{
      ev.motion.x, ev.motion.y, btn
    };
  }
}
