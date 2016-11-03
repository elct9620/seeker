// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace Ruby {
    namespace UI {
      ButtonWidget::~ButtonWidget() {
        Engine::Instance()->ReleaseObject(_OnClickCB);
      }
      // mrb methods
      mrb_data_type ButtonWidget::Type = {"ButtonWidget", &mrb_free_widget};

      void ButtonWidget::mrb_free_widget(mrb_state*, void* ptr) {
        ButtonWidget* btn = static_cast<ButtonWidget*>(ptr);
        if(btn) {
          delete btn;
        }
      }

      void ButtonWidget::init(RClass* klass) {
        Engine* engine = Engine::Instance();

        engine->DefineMethod(klass, "initialize", &mrb_initialize, MRB_ARGS_OPT(2));
      }

      mrb_value ButtonWidget::mrb_initialize(mrb_state* mrb, mrb_value self) {
        ButtonWidget* widget = static_cast<ButtonWidget*>(DATA_PTR(self));

        if(widget) {
          delete widget;
        }

        DATA_PTR(self) = NULL;

        mrb_value label;
        mrb_bool givenLabel;
        mrb_value options;
        mrb_bool givenOptions;
        mrb_get_args(mrb, "|S?H?", &label, &givenLabel, &options, &givenOptions);

        string _label;
        if(givenLabel) {
          _label = string(mrb_str_to_cstr(mrb, label));
        }

        mrb_value x, y;
        mrb_value bg = mrb_nil_value(); // TODO: Prevent assign an nil object
        if(givenOptions) {
          x = mrb_hash_get(mrb, options, mrb_check_intern_cstr(mrb, "x"));
          y = mrb_hash_get(mrb, options, mrb_check_intern_cstr(mrb, "y"));
          bg = mrb_hash_get(mrb, options, mrb_check_intern_cstr(mrb, "bg"));
        }

        mrb_int _x = mrb_fixnum(x);
        mrb_int _y = mrb_fixnum(y);
        string _bg;

        if(!mrb_nil_p(bg)) {
          _bg = string(mrb_str_to_cstr(mrb, bg));
        }

        void *p = mrb_malloc(mrb, sizeof(ButtonWidget));
        widget = new (p) ButtonWidget(mrb_obj_ptr(self), _label, _x, _y, _bg);

        DATA_TYPE(self) = &Type;
        DATA_PTR(self) = widget;

        return self;
      }

      // Instance Method
      void ButtonWidget::Update() {
      }

      void ButtonWidget::OnClick() {
        Engine::Instance()->CallWithBlock(RubyInstance(), "instance_eval", 0, NULL, _OnClickCB);
      }
    }
  }
}
