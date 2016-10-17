// Copyright 2016 Zheng Xian Qiu

#pragma once

#ifndef EVENT_H_
#define EVENT_H_

#include <vector>

#include "Seeker.h"

#include "EventType.h"
#include "ISubscriber.h"

using std::vector;

namespace Seeker {

  class Event {
    public:
      static void refresh();

      static void on(ISubscriber* event);
      static void off(ISubscriber* event);
      static bool exists(ISubscriber* event);
      static void dispatch(const EventType type);

    private:
      static vector<ISubscriber*> subscribers;
  };
}

#endif
