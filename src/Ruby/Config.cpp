// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace Ruby {
    void Config::init(RClass* klass) {
      Engine* engine = Engine::Instance();

      engine->DefineModuleMethod(klass, "name", &Config::mrb_set_name, MRB_ARGS_REQ(1));
      engine->DefineModuleMethod(klass, "width", &Config::mrb_set_width, MRB_ARGS_REQ(1));
      engine->DefineModuleMethod(klass, "height", &Config::mrb_set_height, MRB_ARGS_REQ(1));
    }

    mrb_value Config::mrb_set_name(mrb_state* mrb, mrb_value self) {
      mrb_value name;
      mrb_get_args(mrb, "S", &name);

      Seeker::Config::Window.Name = string(mrb_str_to_cstr(mrb, name));

      return self;
    }

    mrb_value Config::mrb_set_width(mrb_state* mrb, mrb_value self) {
      mrb_int _width;
      mrb_get_args(mrb, "i", &_width);

      Seeker::Config::Window.Width = _width;

      return self;
    }

    mrb_value Config::mrb_set_height(mrb_state* mrb, mrb_value self) {
      mrb_int _height;
      mrb_get_args(mrb, "i", &_height);

      Seeker::Config::Window.Height = _height;
      return self;
    }
  }
}
