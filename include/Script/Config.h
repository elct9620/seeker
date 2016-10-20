// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

#ifndef _SCRIPT_CONFIG_H
#define _SCRIPT_CONFIG_H

namespace Seeker {
  namespace Script {
    class Config {
      public:
        static void init(RClass*);

        static mrb_value setName(mrb_state* mrb, mrb_value self);
        static mrb_value setWidth(mrb_state* mrb, mrb_value self);
        static mrb_value setHeight(mrb_state* mrb, mrb_value self);
    };
  }
}

#endif
