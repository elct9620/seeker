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

        void loadScript(const string &filename);
        void executeScript(const string &script);
        void captureException();

        template<class T>
        void defineClass(void (*callback)(RClass*));
        template<class T>
        void defineClass(void (*callback)(RClass*), RClass* parent);

        void defineMethod(RClass* klass, mrb_func_t func, mrb_aspec aspec);

      private:
        Engine();
        ~Engine();

        RClass* createClass(string name, RClass* parent);
        mrb_data_type* createDataType(string name);

        template<class T>
        static mrb_value classInitializer(mrb_state* mrb, mrb_value self);

      private:
        static Engine* _instance;
        static string basePath;

        static unordered_map<string, RClass*> definedClass;
        static unordered_map<string, mrb_data_type> definedType;

        mrb_state* mrb;
    };
  }
}

#endif
