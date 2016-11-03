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
      _background = nullptr;

      if(!bgPath.empty()) {
        _background = Resource<Texture>::Load(bgPath);
        _width = _background->Width;
        _height = _background->Height;
      }

      Event::Instance()->Register(this);
    }

    ButtonWidget::~ButtonWidget() {
      if(_background) {
        _background->Destroy();
      }
    }

    void ButtonWidget::Update() {
    }

    void ButtonWidget::Draw() {
      if(_background) {
        _background->Draw(_x, _y);
      }
    }

    void ButtonWidget::OnClick() {
    }

  }
}
