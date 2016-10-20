// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace Script {
    void Config::init(RClass* klass) {
      Engine* engine = Engine::instance();

      engine->defineModuleMethod(klass, "name", &Config::setName, MRB_ARGS_REQ(1));
      engine->defineModuleMethod(klass, "width", &Config::setWidth, MRB_ARGS_REQ(1));
      engine->defineModuleMethod(klass, "height", &Config::setHeight, MRB_ARGS_REQ(1));
    }

    mrb_value Config::setName(mrb_state* mrb, mrb_value self) {
      mrb_value name;
      mrb_get_args(mrb, "S", &name);

      Seeker::Config::Window.name = string(mrb_str_to_cstr(mrb, name));

      return self;
    }

    mrb_value Config::setWidth(mrb_state* mrb, mrb_value self) {
      mrb_int _width;
      mrb_get_args(mrb, "i", &_width);

      Seeker::Config::Window.width = _width;

      return self;
    }

    mrb_value Config::setHeight(mrb_state* mrb, mrb_value self) {
      mrb_int _height;
      mrb_get_args(mrb, "i", &_height);

      Seeker::Config::Window.height = _height;
      return self;
    }
  }
}
