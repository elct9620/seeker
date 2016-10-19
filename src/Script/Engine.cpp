// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace Script {
    string Engine::basePath = string(SDL_GetBasePath());

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
  }
}
