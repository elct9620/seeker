// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace UI {
    ButtonWidget::ButtonWidget(string label) {
      ButtonWidget(label, 0, 0);
    }

    ButtonWidget::ButtonWidget(string label, int x, int y) {
      ButtonWidget(label, x, y, "");
    }

    ButtonWidget::ButtonWidget(string label, int x, int y, string bgPath) {
      _label = label;
      _x = x;
      _y = y;

      if(!bgPath.empty()) {
        _background = Resource<Texture>::Load(bgPath);
      }

      Event::Instance()->Register(this);
    }

    ButtonWidget::~ButtonWidget() {
      _background->Destroy();
    }

    void ButtonWidget::Update() {
    }

    void ButtonWidget::Draw() {
    }

    void ButtonWidget::OnClick() {
    }

  }
}
