// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

#ifndef _RUBY_GAME_H
#define _RUBY_GAME_H

namespace Seeker {
  namespace Ruby {
    class Game {
      public:
        static void init(RClass*);

        static mrb_value config(mrb_state* mrb, mrb_value self);
    };
  }
}

#endif
