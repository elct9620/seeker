// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"

#ifndef _RUBY_H
#define _RUBY_H

namespace Seeker {
  class Ruby : public IScript {
    public:
      void loadCore();
      void loadScript();
  };

  class FRuby : public IScript {
    public:
      void loadCore() {};
      void loadScript() {};
  };
}

#endif
