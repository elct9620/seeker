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

    void Scene::mrb_free_scene(mrb_state* mrb, void* ptr) {
      Scene* scene = static_cast<Scene*>(ptr);
      if(scene) {
        // Object didn't move into C++ world, free it by Ruby
        scene->~Scene();
        mrb_free(mrb, ptr);
      }
    }

    mrb_value Scene::mrb_initialize(mrb_state* mrb, mrb_value self) {
      Scene* scene = static_cast<Scene*>(DATA_PTR(self));

      if(scene) {
        delete scene;
      }

      mrb_value name;
      mrb_get_args(mrb, "S", &name);

      string sceneName(mrb_str_to_cstr(mrb, name));
      void* p  = mrb_malloc(mrb, sizeof(Scene));
      scene = new (p) Scene(mrb_obj_ptr(self), sceneName);

      DATA_PTR(self) = scene;
      DATA_TYPE(self) = &Type;

      return self;
    }

    mrb_value Scene::mrb_add(mrb_state* mrb, mrb_value self) {
      Scene* scene = static_cast<Scene*>(mrb_get_datatype(mrb, self, &Type));

      mrb_value object;
      mrb_get_args(mrb, "o", &object);

      // TODO: Define GameObject data type
      Actor* actor = static_cast<Actor*>(mrb_get_datatype(mrb, object, &Actor::Type));

      if(actor && scene) {
        scene->add(actor);
        mrb_gc_register(mrb, object);
      } else {
        // TODO: create ruby error
        Logger::Error("Cannot add non GameObject into Scene.");
      }

      return self;
    }

    mrb_value Scene::mrb_to(mrb_state* mrb, mrb_value self) {
      Scene* scene = static_cast<Scene*>(mrb_get_datatype(mrb, self, &Type));

      mrb_value nextScene;
      mrb_get_args(mrb, "o", &nextScene);

      Scene* _nextScene = static_cast<Scene*>(mrb_get_datatype(mrb, nextScene, &Type));
      if(_nextScene) {
        scene->to(_nextScene);
        // Move GC controller into C++
        mrb_gc_register(mrb, nextScene);
      } else {
        // TODO: create ruby error
        Logger::Error("Cannot transition to non Scene object");
      }

      return self;
    }

    // Instance Method
    Scene::~Scene() {
    }

  }
}
