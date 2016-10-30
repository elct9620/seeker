// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"

#ifndef _RUBY_RUBY_OBJECT_H
#define _RUBY_RUBY_OBJECT_H

namespace Seeker {
  namespace Ruby {
    class RubyObject {
      public:
        RubyObject(RObject* object) : _object(object) {};

        virtual ~RubyObject() {
          mrb_value object = mrb_obj_value(_object);
          Engine::Instance()->ReleaseObject(object);
          DATA_PTR(object) = NULL;
        };

      private:
        RObject* _object;
    };
  }
}

#endif
