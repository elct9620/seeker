// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <string>

#include "Seeker.h"

#include "mruby.h"
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

        void loadScript(const string &filename);
        void executeScript(const string &script);
        void captureException();

      private:
        Engine();
        ~Engine();

      private:
        static Engine* _instance;
        static string basePath;

        mrb_state* mrb;
    };
  }
}

#endif
