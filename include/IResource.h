// Copyright 2016 Zheng Xian Qiu

#pragma once

#ifndef IRESOURCE_H_
#define IRESOURCE_H_

namespace Seeker {
  class IResource {
    template<class T> friend class Resource;

    private:
      void incReference() { _references++; };
      void decReference() { _references--; };
      int getReferenceCount() { return _references; }

      int _references;
  };
}

#endif
