// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <stdexcept>

#ifndef ERRORS_H_
#define ERRORS_H_

using namespace std;

namespace Seeker {
  class ResouceError : public runtime_error {
    public:
      ResouceError(const char* what) : std::runtime_error(what) {}
  };
}

#endif
