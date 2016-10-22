// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace Ruby {

    void Scene::init(RClass* klass) {
      Engine* engine = Engine::instance();

      engine->defineMethod(klass, "initialize", &Scene::mrb_initialize, MRB_ARGS_REQ(1));
      engine->defineMethod(klass, "add", &Scene::mrb_add, MRB_ARGS_REQ(1));
      engine->defineMethod(klass, "to", &Scene::mrb_to, MRB_ARGS_REQ(1));
    }

    mrb_value Scene::mrb_initialize(mrb_state* mrb, mrb_value self) {
      Scene* scene = static_cast<Scene*>(DATA_PTR(self));

      if(scene) {
        delete scene;
      }

      mrb_value name;
      mrb_get_args(mrb, "S", &name);

      string sceneName(mrb_str_to_cstr(mrb, name));
      scene = new (mrb_alloca(mrb, sizeof(Scene))) Scene(sceneName);

      DATA_PTR(self) = scene;

      return self;
    }

    mrb_value Scene::mrb_add(mrb_state* mrb, mrb_value self) {
      Scene* scene = static_cast<Scene*>(DATA_PTR(self));

      mrb_value object;
      mrb_get_args(mrb, "o", &object);

      ::Seeker::GameObject* gameObject = static_cast<::Seeker::GameObject*>(DATA_PTR(object));

      if(gameObject) {
        scene->add(gameObject);
      } else {
        // TODO: create ruby error
        Logger::Error("Cannot add non GameObject into Scene.");
      }

      return self;
    }

    mrb_value Scene::mrb_to(mrb_state* mrb, mrb_value self) {
      Scene* scene = static_cast<Scene*>(DATA_PTR(self));

      mrb_value nextScene;
      mrb_get_args(mrb, "o", &nextScene);

      Scene* _nextScene = static_cast<Scene*>(DATA_PTR(nextScene));
      if(_nextScene) {
        scene->to(_nextScene);
      } else {
        // TODO: create ruby error
        Logger::Error("Cannot transition to non Scene object");
      }

      return self;
    }

  }
}
