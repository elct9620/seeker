// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace Ruby {

    void Game::init(RClass* klass) {
      Engine* engine = Engine::Instance();

      engine->DefineModuleMethod(klass, "config", &Game::mrb_config, MRB_ARGS_BLOCK());
      engine->DefineModuleMethod(klass, "set_scene", &Game::mrb_set_scene, MRB_ARGS_REQ(1));
      engine->DefineModuleMethod(klass, "fps", &Game::mrb_fps, MRB_ARGS_NONE());
    }

    mrb_value Game::mrb_config(mrb_state* mrb, mrb_value self) {

      mrb_value proc;
      mrb_get_args(mrb, "&", &proc);

      mrb_sym classEval(mrb_intern_cstr(mrb, "class_eval"));
      RClass* klass = Engine::Instance()->Module("Config");
      if(klass) {
        mrb_value module = mrb_obj_value(klass);
        mrb_funcall_with_block(mrb, module, classEval, 0, NULL, proc);
      }

      return self;
    }

    // TODO: split into GameState module
    mrb_value Game::mrb_set_scene(mrb_state* mrb, mrb_value self) {
      mrb_value scene;
      mrb_get_args(mrb, "o", &scene);

      Scene* _scene = static_cast<Scene*>(mrb_get_datatype(mrb, scene, &Scene::Type));
      if(_scene) {
        // TODO: implement alias for get game state
        Seeker::Framework::Game()->State()->TransitionTo(_scene);
        Engine::Instance()->FreezeObject(scene);
      } else {
        // TODO: create ruby error
        Logger::Error("The object is not valid Scene object");
      }

      return self;
    }

    mrb_value Game::mrb_fps(mrb_state* mrb, mrb_value) {
      return mrb_float_value(mrb, Framework::Instance()->Game()->GetFPS());
    }
  }
}
