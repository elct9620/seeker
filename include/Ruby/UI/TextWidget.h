// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"

#ifndef _RUBY_UI_TEXTWIDGET_H
#define _RUBY_UI_TEXTWIDGET_H

using std::string;

namespace Seeker  {
  namespace Ruby {
    namespace UI {
      class TextWidget : public Seeker::UI::TextWidget, public RubyObject {
        public:
          TextWidget(RObject* object, string text) : Seeker::UI::TextWidget(text), RubyObject(object) {};
          TextWidget(RObject* object, string text, int x, int y) : Seeker::UI::TextWidget(text, x, y), RubyObject(object) {};
          ~TextWidget();

          virtual void Update();

          // mruby methods
          static struct mrb_data_type Type;
          static void init(RClass* klass);
          static void mrb_free_widget(mrb_state* mrb, void *ptr);
          static mrb_value mrb_initialize(mrb_state* mrb, mrb_value self);
          static mrb_value mrb_set_text(mrb_state* mrb, mrb_value self);
          static mrb_value mrb_set_x(mrb_state* mrb, mrb_value self);
          static mrb_value mrb_set_y(mrb_state* mrb, mrb_value self);
          static mrb_value mrb_update(mrb_state* mrb, mrb_value self);

        private:
          mrb_value _UpdateCB;
      };
    }
  }
}
#endif
