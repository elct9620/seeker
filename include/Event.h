// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"

#ifndef _EVENT_H
#define _EVENT_H

namespace Seeker {
  class Event {
  };

  // Mouse Event
  class MouseEvent : public Event {
    public:
      enum Button {
        Left,
        Middle,
        Right
      };

      MouseEvent(int x, int y, Button which)
        : x(x), y(y), button(which) {};

      int x = 0;
      int y = 0;
      int wheel = 0;
      Button button;
  };
}

#endif
