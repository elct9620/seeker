// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace Ruby {
    void Actor::init(RClass* klass) {
      Engine* engine = Engine::instance();

      engine->defineMethod(klass, "initialize", &Actor::mrb_initialize, MRB_ARGS_REQ(1) | MRB_ARGS_OPT(2));
    }

    mrb_data_type Actor::Type = {"Actor", &Actor::mrb_free_actor};

    void Actor::mrb_free_actor(mrb_state* mrb, void* ptr) {
      Actor* actor = static_cast<Actor*>(ptr);
      if(actor) {
        actor->~Actor();
        mrb_free(mrb, ptr);
      }
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
      void* p = mrb_malloc(mrb, sizeof(Actor));
      actor = new (p) Actor(mrb_obj_ptr(self), _filename, x, y);

      DATA_PTR(self) = actor;
      DATA_TYPE(self) = &Type;

      return self;
    }

    // Actor Instance Method
    Actor::Actor(RObject* _object, const string& filename, int x, int y)
      : Seeker::Actor(filename, x, y), RubyObject(_object) {
    }

    Actor::~Actor() {
    }
  }
}
