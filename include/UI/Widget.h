// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"

#ifndef _UI_WIDGET_H
#define _UI_WIDGET_H

using std::vector;

namespace Seeker {
  class GameState;

  namespace UI {
    class Widget {
      friend class Seeker::GameState;

      public:
        Widget();
        Widget(int x, int y);
        virtual ~Widget();

        void AddChild(Widget* child);
        void SetVisible(bool visible);
        void SetPosition(int x, int y);

        int SetX(int x);
        int SetY(int y);
        int SetZ(int z);
        int X() { return _x; }
        int Y() { return _y; }
        int Z() { return _z; }
        int ZIndex() { return Z(); }
        int ZIndex(int z);

        int Width() { return _width; }
        int Height() { return _height; }

        virtual void Update() = 0;
        virtual void Draw() = 0;
        virtual void Destroy() {};

        static bool ZOrderCompare(Widget* a, Widget* b) {
          return a->ZIndex() > b->ZIndex();
        }

      protected:
        int _x = 0;
        int _y = 0;
        int _z = 0;
        int _width = 0;
        int _height = 0;
        bool visible = true;

        Widget* parent = nullptr;

        void ReSortChildren();

      private:
        void _Update();
        void _Render();

        vector<Widget*> _widgets = {};

    };
  }
}

#endif
