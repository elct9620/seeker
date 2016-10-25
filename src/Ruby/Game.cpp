// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace Ruby {

    void Game::init(RClass* klass) {
      Engine* engine = Engine::instance();

      engine->defineModuleMethod(klass, "config", &Game::config, MRB_ARGS_BLOCK());
      engine->defineModuleMethod(klass, "set_scene", &Game::setScene, MRB_ARGS_REQ(1));
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

    // TODO: split into GameState module
    mrb_value Game::setScene(mrb_state* mrb, mrb_value self) {
      mrb_value scene;
      mrb_get_args(mrb, "o", &scene);

      Scene::RScene* _rscene = static_cast<Scene::RScene*>(DATA_PTR(scene));
      Seeker::Scene* _scene = _rscene->get();
      if(_scene) {
        // TODO: implement alias for get game state
        Logger::Info("Set current scene to %s", _scene->getName().c_str());
        ::Seeker::Framework::getInstance()->getGameInstance()->getState()->transitionTo(_scene);
      } else {
        // TODO: create ruby error
        Logger::Error("The object is not valid Scene object");
      }

      return self;
    }
  }
}
