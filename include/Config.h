// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <string>

#include "Seeker.h"

#ifndef _CONFIG_H
#define _CONFIG_H

using std::string;

namespace Seeker {
  class Config {
    public:
      static struct WindowSetting {
        string Name;
        int Width;
        int Height;
      } Window;

    private:
      Config();
  };
}

#endif
