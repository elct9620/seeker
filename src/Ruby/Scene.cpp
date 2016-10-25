// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace Ruby {

    struct mrb_data_type Scene::Type = { "Scene", &Scene::mrb_free_scene };

    void Scene::init(RClass* klass) {
      Engine* engine = Engine::instance();

      engine->defineMethod(klass, "initialize", &Scene::mrb_initialize, MRB_ARGS_REQ(1));
      engine->defineMethod(klass, "add", &Scene::mrb_add, MRB_ARGS_REQ(1));
      engine->defineMethod(klass, "to", &Scene::mrb_to, MRB_ARGS_REQ(1));
    }

    void Scene::mrb_free_scene(mrb_state*, void*) {
    }

    mrb_value Scene::mrb_initialize(mrb_state* mrb, mrb_value self) {
      RScene* rscene = static_cast<RScene*>(DATA_PTR(self));

      if(rscene) {
        mrb_free(mrb, rscene);
      }

      mrb_value name;
      mrb_get_args(mrb, "S", &name);

      string sceneName(mrb_str_to_cstr(mrb, name));
      rscene  = (RScene*)mrb_malloc(mrb, sizeof(RScene));
      rscene->sceneName = sceneName;

      // Initialize Game Scene
      Seeker::Scene::create(sceneName);

      DATA_PTR(self) = rscene;
      DATA_TYPE(self) = &Type;

      return self;
    }

    mrb_value Scene::mrb_add(mrb_state* mrb, mrb_value self) {
      RScene* rscene = static_cast<RScene*>(mrb_get_datatype(mrb, self, &Type));

      mrb_value object;
      mrb_get_args(mrb, "o", &object);

      // TODO: Define GameObject data type
      Actor::RActor *actor = (Actor::RActor*)DATA_PTR(object);
      Seeker::GameObject* gameObject = static_cast<Seeker::GameObject*>(actor->p);
      Seeker::Scene* scene = rscene->get();

      if(gameObject && scene) {
        scene->add(gameObject);
      } else {
        // TODO: create ruby error
        Logger::Error("Cannot add non GameObject into Scene.");
      }

      return self;
    }

    mrb_value Scene::mrb_to(mrb_state* mrb, mrb_value self) {
      RScene* rscene = static_cast<RScene*>(mrb_get_datatype(mrb, self, &Type));
      Seeker::Scene* scene = rscene->get();

      mrb_value nextScene;
      mrb_get_args(mrb, "o", &nextScene);

      RScene* _nextRScene = static_cast<RScene*>(mrb_get_datatype(mrb, nextScene, &Type));
      Seeker::Scene* _nextScene = _nextRScene->get();
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
