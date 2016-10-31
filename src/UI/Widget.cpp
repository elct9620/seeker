// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace UI {
    Widget::Widget() {
    }

    Widget::~Widget() {
      for(auto widget : _widgets) {
        widget->Destroy();
        delete widget;
      }
    }

    void Widget::AddChild(Widget* widget) {
      widget->parent = this;
      _widgets.push_back(widget);
    }

    void Widget::SetVisible(bool _visible) {
      visible = _visible;
    }

    void Widget::SetPosition(int _x, int _y) {
      x = _x;
      y = _y;
    }

    void Widget::_Update() {
      if(!visible) return;

      for(auto widget : _widgets) {
        widget->_Update();
      }
      Update();
    }

    void Widget::_Render() {
      if(!visible) return;

      for(auto widget : _widgets) {
        widget->_Render();
      }
      if(visible) Draw();
    }
  }
}
