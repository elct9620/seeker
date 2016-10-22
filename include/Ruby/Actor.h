// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"

#ifndef _RUBY_ACTOR_H
#define _RUBY_ACTOR_H

namespace Seeker {
  namespace Ruby {
    class Actor : public ::Seeker::Actor {
      public:
        Actor(const string &filename, int x, int y) : ::Seeker::Actor(filename, x, y) {};

        // Ruby DSL
        static void init(RClass* klass);
        static mrb_value mrb_initialize(mrb_state* mrb, mrb_value self);
    };
  }
}

#endif
