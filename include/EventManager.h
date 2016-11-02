// Copyright 2016 Zheng Xian Qiu

#pragma once

#ifndef _EVENT_MANAGER_H
#define _EVENT_MANAGER_H

#include <vector>

#include "Seeker.h"

#include "EventType.h"
#include "ISubscriber.h"

using std::vector;

namespace Seeker {

  class EventManager {
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
