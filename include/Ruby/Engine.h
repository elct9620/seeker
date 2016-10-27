// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <string>
#include <unordered_map>

#include "Seeker.h"

#include "mruby.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/string.h"
#include "mruby/compile.h"
#include "mruby/value.h"

#ifndef _RUBY_ENGINE_H
#define _RUBY_ENGINE_H

using std::string;

namespace Seeker {
  namespace Ruby {
    class Engine {
      public:
        static Engine* Instance();

        static mrb_data_type* DataType(string name);
        static RClass* Class(string name);
        static RClass* Module(string name);

        void LoadScript(const string &filename);
        void ExecuteScript(const string &script);
        void CaptureException();

        void FreezeObject(mrb_value object);
        void ReleaseObject(mrb_value object);

        template<class T>
        void DefineClass(string name, void (*callback)(RClass*)) {
            DefineClass<T>(name, callback, mrb->object_class);
        }

        template<class T>
        void DefineClass(string name, void (*callback)(RClass*), RClass* parent) {
          RClass* klass = CreateClass(name, parent);

          if(callback) {
            callback(klass);
          }
        }

        template<class T>
        void DefineModule(string name, void (*callback)(RClass*)) {
          RClass* klass = Module(name);

          if(klass == nullptr) {
            klass = mrb_define_module(mrb, name.c_str());
            definedModule.insert(std::pair<string, RClass*>(name, klass));
          }

          if(callback) {
            callback(klass);
          }
        }

        void DefineMethod(RClass* klass, string name,  mrb_func_t func, mrb_aspec aspec);
        void DefineClassMethod(RClass* klass, string name, mrb_func_t func, mrb_aspec aspec);
        void DefineModuleMethod(RClass* klass, string name, mrb_func_t func, mrb_aspec aspec);


      private:
        Engine();
        ~Engine();

        RClass* CreateClass(string name, RClass* parent);
        mrb_data_type* CreateDataType(string name);

      private:
        static Engine* _instance;
        static string basePath;

        static unordered_map<string, RClass*> definedClass;
        static unordered_map<string, mrb_data_type> definedType;
        static unordered_map<string, RClass*> definedModule;

        mrb_state* mrb;
    };
  }
}

#endif
