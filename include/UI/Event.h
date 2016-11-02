// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"
#include "ISubscriber.h"

#ifndef _UI_EVENT_H
#define _UI_EVENT_H

using std::vector;

namespace Seeker {
  namespace UI {
    class Widget;

    class Event : public ISubscriber {
      public:
        static Event* Instance();

        virtual void OnEvent(EventType type, Seeker::Event& event);

        virtual void OnKeyDown();
        virtual void OnMouseDown(MouseEvent& event);

        bool Exists(Widget* widget);

        void Register(Widget* widget);
        void UnRegister(Widget* widget);

        void ReSortSubscriber();

        static bool WidgetEventWeightCompare(Widget* a, Widget* b);
      private:
        Event();
        ~Event();

        static Event* _instance;

        vector<Widget*> _widgets = {};
    };
  }
}

#endif
