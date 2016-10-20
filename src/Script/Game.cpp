// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace Script {

    void Game::init(RClass* klass) {
      Engine* engine = Engine::instance();

      engine->defineModuleMethod(klass, "config", &Game::config, MRB_ARGS_BLOCK());
    }

    mrb_value Game::config(mrb_state* mrb, mrb_value self) {

      mrb_value proc;
      mrb_get_args(mrb, "&", &proc);

      mrb_sym classEval(mrb_intern_cstr(mrb, "class_eval"));
      RClass* klass = Engine::instance()->getModule("Config");
      if(klass) {
        mrb_value module = mrb_obj_value(klass);
        mrb_funcall_with_block(mrb, module, classEval, 0, NULL, proc);
      }

      return self;
    }

  }
}
