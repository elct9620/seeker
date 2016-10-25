// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <string>

#include "Seeker.h"

#ifndef _RUBY_SCENE_H
#define _RUBY_SCENE_H

namespace Seeker {
  namespace Ruby {
    class Scene {
      public:

        struct RScene {
          string sceneName;
          Seeker::Scene* get() {
            return Seeker::Scene::get(sceneName);
          }
        };

        // mruby methods
        static struct mrb_data_type Type;
        static void init(RClass* klass);
        static void mrb_free_scene(mrb_state* mrb, void* ptr);
        static mrb_value mrb_initialize(mrb_state* mrb, mrb_value self);
        static mrb_value mrb_add(mrb_state* mrb, mrb_value self);
        static mrb_value mrb_to(mrb_state* mrb, mrb_value self);

      private:
        ~Scene();
    };
  }
}

#endif
