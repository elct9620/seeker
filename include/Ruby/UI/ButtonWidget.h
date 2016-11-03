// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"
#include "mruby/hash.h"

#ifndef _RUBY_UI_BUTTON_WIDGET_H
#define _RUBY_UI_BUTTON_WIDGET_H

namespace Seeker {
  namespace Ruby {
    namespace UI {
      class ButtonWidget : public Seeker::UI::ButtonWidget, public RubyObject {
        public:
          ButtonWidget(RObject* object, string label, int x, int y, string bgPath)
            : Seeker::UI::ButtonWidget(label, x, y, bgPath), RubyObject(object) {};
          ~ButtonWidget();

          void Update();
          void OnClick();

          // mrb methods
          static struct mrb_data_type Type;
          static void init(RClass* klass);
          static void mrb_free_widget(mrb_state* mrb, void* ptr);
          static mrb_value mrb_initialize(mrb_state* mrb, mrb_value self);
          static mrb_value mrb_click(mrb_state* mrb, mrb_value self);

        private:
          mrb_value _OnClickCB;
      };
    }
  }
}

#endif
