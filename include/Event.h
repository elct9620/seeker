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
      static void Refresh();

      static void On(ISubscriber* event);
      static void Off(ISubscriber* event);
      static bool Exists(ISubscriber* event);
      static void Dispatch(const EventType type);

    private:
      static vector<ISubscriber*> subscribers;
  };
}

#endif
