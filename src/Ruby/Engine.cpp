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

    Engine* Engine::Instance() {
      if(_instance == NULL) {
        _instance = new Engine;
      }
      return _instance;
    }

    mrb_data_type* Engine::DataType(string name) {
      auto it = definedType.find(name);
      if(it != definedType.end()) {
        return &(*it).second;
      }

      return nullptr;
    }

    RClass* Engine::Class(string name) {
      auto it = definedClass.find(name);
      if(it != definedClass.end()) {
        return (*it).second;
      }

      return nullptr;
    }

    RClass* Engine::Module(string name) {
      auto it = definedModule.find(name);
      if(it != definedModule.end()) {
        return (*it).second;
      }

      return nullptr;
    }

    Engine* Engine::_instance = Engine::Instance();

    // Engine Core
    void Engine::LoadScript(const string &filename) {
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

      CaptureException();
    }

    void Engine::ExecuteScript(const string &script) {
      mrb_load_string(mrb, script.c_str());
      CaptureException();
    }

    void Engine::CaptureException() {
      if(mrb->exc) {
        mrb_value exc = mrb_obj_value(mrb->exc);
        Logger::Error(mrb_str_to_cstr(mrb, mrb_inspect(mrb, exc)));
      }
    }

    void Engine::FreezeObject(mrb_value object) {
      mrb_gc_register(mrb, object);
    }

    void Engine::ReleaseObject(mrb_value object) {
      mrb_gc_unregister(mrb, object);
    }

    void Engine::Call(mrb_value object, string methodName, mrb_int argc, mrb_value* argv) {
      mrb_funcall_argv(mrb, object, mrb_intern_cstr(mrb, methodName.c_str()), argc, argv);
    }

    void Engine::CallWithBlock(mrb_value object, string methodName, mrb_int argc, mrb_value* argv, mrb_value block) {
      mrb_funcall_with_block(mrb, object, mrb_intern_cstr(mrb, methodName.c_str()), argc, argv, block);
    }

    void Engine::DefineMethod(RClass* klass, string name, mrb_func_t func, mrb_aspec aspec) {
      mrb_define_method(mrb, klass, name.c_str(), func, aspec);
    }

    void Engine::DefineClassMethod(RClass* klass, string name, mrb_func_t func, mrb_aspec aspec) {
      mrb_define_class_method(mrb, klass, name.c_str(), func, aspec);
    }

    void Engine::DefineModuleMethod(RClass* klass, string name, mrb_func_t func, mrb_aspec aspec) {
      mrb_define_module_function(mrb, klass, name.c_str(), func, aspec);
    }

    RClass* Engine::CreateClass(string name, RClass* parent) {
      RClass* klass = Class(name);

      if(klass == nullptr) {
        klass = mrb_define_class(mrb, name.c_str(), parent);
        MRB_SET_INSTANCE_TT(klass, MRB_TT_DATA);
        definedClass.insert(std::pair<string, RClass*>(name, klass));
      }

      return klass;
    }

    mrb_data_type* Engine::CreateDataType(string name) {
      mrb_data_type* dataType = DataType(name);
      if(dataType) {
        return dataType;
      }

      mrb_data_type newType = { name.c_str(), mrb_free };
      definedType.insert(std::pair<string, mrb_data_type>(name, newType));

      // Redo to get the pointer saved in unorederd map
      return DataType(name);
    }
  }
}
