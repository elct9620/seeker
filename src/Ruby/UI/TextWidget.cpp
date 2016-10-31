// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace Ruby {
    namespace UI {

      struct mrb_data_type TextWidget::Type = { "TextWidget", &TextWidget::mrb_free_widget };

      void TextWidget::init(RClass* klass) {
        Engine* engine = Engine::Instance();

        engine->DefineMethod(klass, "initialize", &mrb_initialize, MRB_ARGS_REQ(1) | MRB_ARGS_OPT(2));
        engine->DefineMethod(klass, "text=", &mrb_set_text, MRB_ARGS_REQ(1));
        engine->DefineMethod(klass, "x=", &mrb_set_x, MRB_ARGS_REQ(1));
        engine->DefineMethod(klass, "y=", &mrb_set_y, MRB_ARGS_REQ(1));
        engine->DefineMethod(klass, "update", &mrb_update, MRB_ARGS_BLOCK());
      }

      void TextWidget::mrb_free_widget(mrb_state* mrb, void* ptr) {
        TextWidget* widget = static_cast<TextWidget*>(ptr);
        if(widget) {
          widget->~TextWidget();
          mrb_free(mrb, ptr);
        }
      }

      mrb_value TextWidget::mrb_initialize(mrb_state* mrb, mrb_value self) {
        TextWidget* widget = (TextWidget*) DATA_PTR(self);
        if(widget) {
          delete widget;
        }

        mrb_value text;
        mrb_int x, y;

        mrb_get_args(mrb, "S|ii", &text, &x, &y);

        string _text(mrb_str_to_cstr(mrb, text));

        DATA_PTR(self) = NULL;
        void *p = mrb_malloc(mrb, sizeof(TextWidget));
        widget = new (p) TextWidget(mrb_obj_ptr(self), _text, x, y);

        DATA_PTR(self) = widget;
        DATA_TYPE(self) = &Type;

        return self;
      }

      mrb_value TextWidget::mrb_set_text(mrb_state* mrb, mrb_value self) {
        TextWidget* widget = static_cast<TextWidget*>(mrb_get_datatype(mrb, self, &Type));

        mrb_value text;
        mrb_get_args(mrb, "S", &text);
        string _text(mrb_str_to_cstr(mrb, text));

        if(widget) {
          widget->SetText(_text);
        }

        return text;
      }

      mrb_value TextWidget::mrb_set_x(mrb_state* mrb, mrb_value self) {
        TextWidget* widget = static_cast<TextWidget*>(mrb_get_datatype(mrb, self, &Type));

        mrb_int x;
        mrb_get_args(mrb, "i", &x);

        if(widget) {
          widget->SetPosition(x, widget->Y());
        }

        return mrb_fixnum_value(x);
      }

      mrb_value TextWidget::mrb_set_y(mrb_state* mrb, mrb_value self) {
        TextWidget* widget = static_cast<TextWidget*>(mrb_get_datatype(mrb, self, &Type));

        mrb_int y;
        mrb_get_args(mrb, "i", &y);

        if(widget) {
          widget->SetPosition(widget->X(), y);
        }

        return mrb_fixnum_value(y);
      }

      mrb_value TextWidget::mrb_update(mrb_state* mrb, mrb_value self) {
        TextWidget* widget = static_cast<TextWidget*>(mrb_get_datatype(mrb, self, &Type));

        mrb_value proc;
        mrb_get_args(mrb, "&", &proc);
        if(widget) {
          if(!mrb_nil_p(widget->_UpdateCB)) {
            Engine::Instance()->ReleaseObject(widget->_UpdateCB);
          }
          widget->_UpdateCB = proc;
          Engine::Instance()->FreezeObject(widget->_UpdateCB);
        }

        return self;
      }

      // Instance Method
      TextWidget::~TextWidget() {
      }

      void TextWidget::Update() {
        Engine::Instance()->CallWithBlock(RubyInstance(), "instance_eval", 0, NULL, _UpdateCB);
      }
    }
  }
}
