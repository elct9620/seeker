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

#ifndef _SCRIPT_ENGINE_H
#define _SCRIPT_ENGINE_H

using std::string;

namespace Seeker {
  namespace Script {
    class Engine {
      public:
        static Engine* instance();

        static mrb_data_type* getDataType(string name);
        static RClass* getClass(string name);
        static RClass* getModule(string name);

        void loadScript(const string &filename);
        void executeScript(const string &script);
        void captureException();

        template<class T>
        inline void defineClass(string name, void (*callback)(RClass*)) {
            defineClass<T>(name, callback, mrb->object_class);
        };

        template<class T>
        inline void defineClass(string name, void (*callback)(RClass*), RClass* parent) {
          RClass* klass = createClass(name, parent);

          // TODO: Provide custom initializer options
          mrb_define_method(mrb, klass, "initialize", &Engine::classInitializer<T>, MRB_ARGS_NONE());

          if(callback) {
            callback(klass);
          }
        };

        void defineModule(string name, void (*callback)(RClass*));

        void defineMethod(RClass* klass, string name,  mrb_func_t func, mrb_aspec aspec);

      private:
        Engine();
        ~Engine();

        RClass* createClass(string name, RClass* parent);
        mrb_data_type* createDataType(string name);

        template<class T>
        inline static mrb_value classInitializer(mrb_state* mrb, mrb_value self) {
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
        };

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
