// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"

#ifndef _RUBY_H
#define _RUBY_H

namespace Seeker {
  namespace Script {
    class Ruby : public IScript {
      public:
        void LoadCore();
        void LoadScript();
    };
  }
}

#endif
