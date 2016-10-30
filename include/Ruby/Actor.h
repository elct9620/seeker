// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"

#ifndef _RUBY_ACTOR_H
#define _RUBY_ACTOR_H

namespace Seeker {
  namespace Ruby {
    class Actor : public Seeker::Actor, public RubyObject {
      public:
        Actor(RObject* _object, const string &filename, int x, int y);
        ~Actor();

        // Ruby DSL
        static void init(RClass* klass);
        static mrb_data_type Type;
        static void mrb_free_actor(mrb_state*, void* ptr);
        static mrb_value mrb_initialize(mrb_state* mrb, mrb_value self);
    };
  }
}

#endif
