// Copyright 2016 Zheng Xian Qiu

#pragma once

#ifndef IEVENT_H_
#define IEVENT_H_

#include "Seeker.h"

namespace Seeker {
  class  ISubscriber {
    public:
      virtual void OnEvent(const EventType type, Event& event) = 0;
  };
}

#endif
