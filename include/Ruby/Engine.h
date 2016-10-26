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
        static Engine* instance();

        static mrb_data_type* getDataType(string name);
        static RClass* getClass(string name);
        static RClass* getModule(string name);

        void loadScript(const string &filename);
        void executeScript(const string &script);
        void captureException();

        void freezeObject(mrb_value object);
        void releaseObject(mrb_value object);

        template<class T>
        void defineClass(string name, void (*callback)(RClass*)) {
            defineClass<T>(name, callback, mrb->object_class);
        }

        template<class T>
        void defineClass(string name, void (*callback)(RClass*), RClass* parent) {
          RClass* klass = createClass(name, parent);

          if(callback) {
            callback(klass);
          }
        }

        template<class T>
        void defineModule(string name, void (*callback)(RClass*)) {
          RClass* klass = getModule(name);

          if(klass == nullptr) {
            klass = mrb_define_module(mrb, name.c_str());
            definedModule.insert(std::pair<string, RClass*>(name, klass));
          }

          if(callback) {
            callback(klass);
          }
        }

        void defineMethod(RClass* klass, string name,  mrb_func_t func, mrb_aspec aspec);
        void defineClassMethod(RClass* klass, string name, mrb_func_t func, mrb_aspec aspec);
        void defineModuleMethod(RClass* klass, string name, mrb_func_t func, mrb_aspec aspec);


      private:
        Engine();
        ~Engine();

        RClass* createClass(string name, RClass* parent);
        mrb_data_type* createDataType(string name);

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
