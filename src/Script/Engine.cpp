// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace Script {
    string Engine::basePath = string(SDL_GetBasePath());
    unordered_map<string, RClass*> Engine::definedClass = {};
    unordered_map<string, mrb_data_type> Engine::definedType = {};

    Engine::Engine() {
      mrb = mrb_open();
    }

    Engine::~Engine() {
      mrb_close(mrb);
    }

    Engine* Engine::instance() {
      if(_instance == NULL) {
        _instance = new Engine;
      }
      return _instance;
    }

    mrb_data_type* Engine::getDataType(string name) {
      auto it = definedType.find(name);
      if(it != definedType.end()) {
        return &(*it).second;
      }

      return nullptr;
    }

    RClass* Engine::getClass(string name) {
      auto it = definedClass.find(name);
      if(it != definedClass.end()) {
        return (*it).second;
      }

      return nullptr;
    }

    Engine* Engine::_instance = Engine::instance();

    // Engine Core
    void Engine::loadScript(const string &filename) {
      string fullPath = (basePath + filename);

      FILE *file;
      file = fopen(fullPath.c_str(), "r");

      if(!file) {
        Logger::Error("Script %s load failed!", fullPath.c_str());
        return;
      }

      mrb_load_file(mrb, file);
      Logger::Info("Script %s is loaded.", filename.c_str());

      fclose(file);

      captureException();
    }

    void Engine::executeScript(const string &script) {
      mrb_load_string(mrb, script.c_str());
      captureException();
    }

    void Engine::captureException() {
      if(mrb->exc) {
        mrb_value exception = mrb_obj_value(mrb->exc);
        Logger::Error("Script => %s", mrb_string_value_ptr(mrb, exception));
      }
    }

    template<class T>
    void Engine::defineClass(void(*body)(RClass*)) {
      defineClass<T>(body, mrb->object_class);
    }

    template<class T>
    void Engine::defineClass(void(*callback)(RClass*), RClass* parent) {
      string className(typeid(T).name());
      RClass* klass = createClass(className, parent);

      // TODO: Provide custom initializer options
      mrb_define_method(mrb, klass, "initialize", &Engine::classInitializer<T>, MRB_ARGS_NONE());

      if(callback) {
        callback(klass);
      }
    }

    RClass* Engine::createClass(string name, RClass* parent) {
      RClass* klass = getClass(name);

      if(klass == nullptr) {
        klass = mrb_define_class(mrb, name.c_str(), parent);
        definedClass.insert(std::pair<string, RClass*>(name, klass));
      }

      return klass;
    }

    mrb_data_type* Engine::createDataType(string name) {
      mrb_data_type* dataType = getDataType(name);
      if(dataType) {
        return dataType;
      }

      mrb_data_type newType = { name.c_str(), mrb_free };
      definedType.insert(std::pair<string, mrb_data_type>(name, newType));

      // Redo to get the pointer saved in unorederd map
      return createDataType(name);
    }

    template<class T>
    mrb_value Engine::classInitializer(mrb_state* mrb, mrb_value self) {
      T* application;
      application = (T*) DATA_PTR(self);

      if(application != NULL) {
        delete application;
      }

      string className(typeid(T).name());
      mrb_data_type* dataType = getDataType(className) ;
      if(dataType) {
        DATA_TYPE(self) = dataType;
      }

      DATA_PTR(self) = NULL;

      application = (T*) mrb_alloca(mrb, sizeof(T));

      DATA_PTR(self) = application;

      return self;
    }
  }
}
