// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

// MRB_API mrb_get_backtrace
namespace Seeker {
  namespace Ruby {
    string Engine::basePath = string(SDL_GetBasePath());
    unordered_map<string, RClass*> Engine::definedClass = {};
    unordered_map<string, mrb_data_type> Engine::definedType = {};
    unordered_map<string, RClass*> Engine::definedModule = {};

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

    RClass* Engine::getModule(string name) {
      auto it = definedModule.find(name);
      if(it != definedModule.end()) {
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

      mrbc_context* cxt = mrbc_context_new(mrb);
      mrbc_filename(mrb, cxt, filename.c_str());
      mrb_load_file_cxt(mrb, file, cxt);

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
        mrb_value exc = mrb_obj_value(mrb->exc);
        Logger::Error(mrb_str_to_cstr(mrb, mrb_inspect(mrb, exc)));
      }
    }

    void Engine::defineMethod(RClass* klass, string name, mrb_func_t func, mrb_aspec aspec) {
      mrb_define_method(mrb, klass, name.c_str(), func, aspec);
    }

    void Engine::defineClassMethod(RClass* klass, string name, mrb_func_t func, mrb_aspec aspec) {
      mrb_define_class_method(mrb, klass, name.c_str(), func, aspec);
    }

    void Engine::defineModuleMethod(RClass* klass, string name, mrb_func_t func, mrb_aspec aspec) {
      mrb_define_module_function(mrb, klass, name.c_str(), func, aspec);
    }

    RClass* Engine::createClass(string name, RClass* parent) {
      RClass* klass = getClass(name);

      if(klass == nullptr) {
        klass = mrb_define_class(mrb, name.c_str(), parent);
        MRB_SET_INSTANCE_TT(klass, MRB_TT_DATA);
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
  }
}
