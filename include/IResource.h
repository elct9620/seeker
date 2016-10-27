// Copyright 2016 Zheng Xian Qiu

#pragma once

#ifndef IRESOURCE_H_
#define IRESOURCE_H_

namespace Seeker {
  class IResource {
    template<class T> friend class Resource;

    private:
      void IncReference() { _references++; };
      void DecReference() { _references--; };
      int ReferenceCount() { return _references; }

      int _references = 0;
  };
}

#endif
