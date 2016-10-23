// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace Ruby {
    void Actor::init(RClass* klass) {
      Engine* engine = Engine::instance();

      engine->defineMethod(klass, "initialize", &Actor::mrb_initialize, MRB_ARGS_REQ(1) | MRB_ARGS_OPT(2));
    }

    mrb_value Actor::mrb_initialize(mrb_state* mrb, mrb_value self) {
      Actor* actor = static_cast<Actor*>(DATA_PTR(self));

      if(actor) {
        delete actor;
      }

      mrb_value filename;
      mrb_int x, y;
      mrb_get_args(mrb, "S|ii", &filename, &x, &y);

      string _filename(mrb_str_to_cstr(mrb, filename));
      actor = new (mrb_alloca(mrb, sizeof(Actor))) Actor(_filename, int(x), int(y));

      DATA_PTR(self) = actor;

      return self;
    }
  }
}
