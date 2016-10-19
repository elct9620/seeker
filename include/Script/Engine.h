// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"

#include "mruby.h"

#ifndef _SCRIPT_ENGINE_H
#define _SCRIPT_ENGINE_H

namespace Seeker {
  namespace Script {
    class Engine {
      public:
        static Engine* instance();

      private:
        Engine();
        ~Engine();

      private:
        static Engine* _instance;

        mrb_state* mrb;
    };
  }
}

#endif
