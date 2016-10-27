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
      virtual void LoadCore() = 0;
      virtual void LoadScript() = 0;
      virtual void Render() {};
      virtual void Update(int) {};

      template<class T> static IScript* Engine() {
        const char* name(typeid(T).name());
        auto it = engines.find(name);
        if(it != engines.end()) {
          return (*it).second;
        }

        T* engine = new T;
        engines.insert(std::pair<const char*, IScript*>(name, engine));
        return engine;
      }

      template<class T> static void Init() {
        static_assert(std::is_base_of<IScript, T>::value, "The script engine loader should implement IScript.");
        Engine<T>()->LoadCore();
      }

      template<class T> static void Setup() {
        static_assert(std::is_base_of<IScript, T>::value, "The script engine loader should implement IScript.");
        Engine<T>()->LoadScript();
      }

      static void RenderAll() {
        for(auto it : engines) {
          it.second->Render();
        }
      }

      static void UpdateAll(int delta) {
        for(auto it : engines) {
          it.second->Update(delta);
        }
      }

    private:
      static unordered_map<const char*, IScript*> engines;
  };
}

#endif
