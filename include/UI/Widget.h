// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"

#ifndef _UI_WIDGET_H
#define _UI_WIDGET_H

using std::vector;

namespace Seeker {
  namespace UI {
    class Widget {
      public:
        Widget();
        virtual ~Widget();

        void AddChild(Widget* child);
        void SetVisible(bool visible);
        void SetPosition(int x, int y);

        int X() { return x; }
        int Y() { return y; }

        virtual void Update() = 0;
        virtual void Draw() = 0;
        virtual void Destroy() {};

      protected:
        int x = 0;
        int y = 0;
        bool visible = true;

        Widget* parent = nullptr;

      private:
        void _Update();
        void _Render();

        vector<Widget*> _widgets = {};

    };
  }
}

#endif
