// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <unordered_map>
#include <string>
#include "Seeker.h"

#include "IResource.h"

#ifndef RESOURCE_H_
#define RESOURCE_H_

using std::unordered_map;
using std::string;

namespace Seeker {
  template<class T>
  class Resource {
    public:
      inline static T* Load(const string &filename) {
        static_assert(std::is_base_of<IResource, T>::value, "Load resource should implement IResource interface.");

        if(filename.empty()) {
          throw ResouceError("The resource file name cannot be empty.");
          return nullptr;
        }

        auto it = resources.find(filename); // NOTE: Find why cannot use unordered_map<string, T*>::iterator
        if(it != resources.end()) {
          (*it).second->IncReference();
          return (*it).second;
        }

        T* resource = new T(filename);
        resource->IncReference();

        resources.insert(std::pair<string, T*>(filename, resource));

        Logger::Info("Resource %s is loaded.", filename.c_str());

        return resource;
      }

      inline static bool Unload(const string &filename) {
        if(filename.empty()) {
          Logger::Error("The resource name cannot be empty.");
          return false;
        }

        auto it = resources.find(filename);
        if(it != resources.end()) {
          (*it).second->DecReference();
          if( (*it).second->ReferenceCount() == 0) {
            delete (*it).second;
            resources.erase(it);
            Logger::Debug("Resource %s is unloaded.", filename.c_str());
          }

          return true;
        }
        return false;
      }

    private:
      Resource() {};
      ~Resource() {};

      static unordered_map<string, T*> resources;
  };

  template<class T>
  unordered_map<string, T*> Resource<T>::resources;
}

#endif
