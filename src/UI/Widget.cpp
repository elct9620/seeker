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

      ReSortChildren();
    }

    void Widget::SetVisible(bool _visible) {
      visible = _visible;
    }

    void Widget::SetPosition(int x, int y) {
      _x = x;
      _y = y;
    }

    int Widget::ZIndex(int z) {
      _z = z;
      if(parent) {
        parent->ReSortChildren();
      }
      return _z;
    }

    void Widget::ReSortChildren() {
      std::sort(_widgets.begin(), _widgets.end(), ZOrderCompare);
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
