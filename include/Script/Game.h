// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

#ifndef _SCRIPT_GAME_H
#define _SCRIPT_GAME_H

namespace Seeker {
  namespace Script {
    class Game {
      public:
        static void init(RClass*);

        static mrb_value config(mrb_state* mrb, mrb_value self);
    };
  }
}

#endif
