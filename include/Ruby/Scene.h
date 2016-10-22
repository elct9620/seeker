// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <string>

#include "Seeker.h"

#ifndef _RUBY_SCENE_H
#define _RUBY_SCENE_H

namespace Seeker {
  namespace Ruby {
    class Scene : public ::Seeker::Scene {
      public:
        Scene(string name) : name(name) {
          Logger::Info("Scene %s is created.", name.c_str());
        };

        string getName() { return name; }

        // mruby methods
        static void init(RClass* klass);
        static mrb_value mrb_initialize(mrb_state* mrb, mrb_value self);
        static mrb_value mrb_add(mrb_state* mrb, mrb_value self);

      private:
        string name;
    };
  }
}

#endif
