// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <unordered_map>
#include "Seeker.h"

#ifndef _ISCRIPT_H
#define _ISCRIPT_H

using std::unordered_map;

namespace Seeker {
  class IScript {
    public:
      virtual void loadCore() = 0;
      virtual void loadScript() = 0;
      virtual void render() {};
      virtual void update(int) {};

      template<class T> static IScript* getEngine() {
        const char* name(typeid(T).name());
        auto it = engines.find(name);
        if(it != engines.end()) {
          return (*it).second;
        }

        T* engine = new T;
        engines.insert(std::pair<const char*, IScript*>(name, engine));
        return engine;
      }

      template<class T> static void init() {
        static_assert(std::is_base_of<IScript, T>::value, "The script engine loader should implement IScript.");
        getEngine<T>()->loadCore();
      }

      template<class T> static void setup() {
        static_assert(std::is_base_of<IScript, T>::value, "The script engine loader should implement IScript.");
        getEngine<T>()->loadScript();
      }

      static void renderAll() {
        for(auto it : engines) {
          it.second->render();
        }
      }

      static void updateAll(int delta) {
        for(auto it : engines) {
          it.second->update(delta);
        }
      }

    private:
      static unordered_map<const char*, IScript*> engines;
  };
}

#endif
