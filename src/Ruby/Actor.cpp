// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace Ruby {
    void Actor::init(RClass* klass) {
      Engine* engine = Engine::instance();

      engine->defineMethod(klass, "initialize", &Actor::mrb_initialize, MRB_ARGS_REQ(1) | MRB_ARGS_OPT(2));
    }

    mrb_data_type Actor::Type = {"Actor", &Actor::mrb_free_actor};

    void Actor::mrb_free_actor(mrb_state*, void*) {}

    mrb_value Actor::mrb_initialize(mrb_state* mrb, mrb_value self) {
      RActor* actor = static_cast<RActor*>(DATA_PTR(self));

      if(actor) {
        mrb_free(mrb, actor);
      }

      mrb_value filename;
      mrb_int x, y;
      mrb_get_args(mrb, "S|ii", &filename, &x, &y);

      string _filename(mrb_str_to_cstr(mrb, filename));
      actor = (RActor*)mrb_malloc(mrb, sizeof(RActor));

      actor->p = new Seeker::Actor(_filename, x, y);

      DATA_PTR(self) = actor;
      DATA_TYPE(self) = &Type;

      return self;
    }
  }
}
