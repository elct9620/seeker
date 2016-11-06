// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <string>

#ifndef IRESOURCE_H_
#define IRESOURCE_H_

using std::string;

namespace Seeker {
  class IResource {
    template<class T> friend class Resource;

    public:
      virtual void Destroy() = 0;
      virtual string ResourceKey() = 0;

    private:

      void IncReference() { _references++; };
      void DecReference() { _references--; };
      int ReferenceCount() { return _references; }

      int _references = 0;
  };
}

#endif
