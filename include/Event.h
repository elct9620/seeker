// Copyright 2016 Zheng Xian Qiu

#pragma once

#ifndef EVENT_H_
#define EVENT_H_

#include <vector>

#include "Seeker.h"

#include "EventType.h"
#include "IEvent.h"

using std::vector;

namespace Seeker {

  class Event {
    public:
      static void refresh();

      static void on(IEvent* event);
      static void off(IEvent* event);
      static bool exists(IEvent* event);
      static void dispatch(const EventType type);

    private:
      static vector<IEvent*> events;
  };
}

#endif
