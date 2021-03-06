// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace UI {

    // Global Object
    Event* Event::_instance = Event::Instance();

    Event* Event::Instance() {
      if(!_instance) {
        _instance = new Event;
      }
      return _instance;
    }

    Event::Event() {
      EventManager::On(this);
    }

    Event::~Event() {
      EventManager::Off(this);
    }

    // Subscriber
    void Event::OnEvent(EventType type, Seeker::Event& event) {
      switch(type) {
        case EventType::Mouse:
          // TODO: Implement mouse event with data
          OnMouseDown(static_cast<MouseEvent&>(event));
          break;
        case EventType::Key:
          // TODO: Implement key event with data
          OnKeyDown();
          break;
        default:
          break;
      }
    }

    void Event::OnMouseDown(MouseEvent& event) {
      for(auto it : _widgets) {
        // TODO: Get mouse event data
        if(it->MouseInBound(event.x, event.y)) {
          it->OnClick();
        }

        if(it->BlockEvent()) {
          break;
        }
      }
    }

    void Event::OnKeyDown() {
      // TODO: Implement KeyDown Handler
    }

    bool Event::Exists(Widget* widget) {
      for(auto it : _widgets) {
        if(it == widget) {
          return true;
        }
      }
      return false;
    }

    void Event::Register(Widget* widget) {
      if(Exists(widget)) return;
      _widgets.push_back(widget);
      ReSortSubscriber();
    }

    void Event::UnRegister(Widget* widget) {
      if(!Exists(widget)) return;
      _widgets.erase(std::remove(_widgets.begin(), _widgets.end(), widget), _widgets.end());
    }

    void Event::ReSortSubscriber() {
      std::sort(_widgets.begin(), _widgets.end(), WidgetEventWeightCompare);
    }

    bool Event::WidgetEventWeightCompare(Widget* a, Widget* b) {
      return a->EventWeight() > b->EventWeight();
    }

  }
}
