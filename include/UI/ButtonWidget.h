// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"

#ifndef _UI_BUTTON_WIDGET_H
#define _UI_BUTTON_WIDGET_H

namespace Seeker {
  class Texture;

  namespace UI {
    class ButtonWidget : public Widget {
      public:
        ButtonWidget(string label);
        ButtonWidget(string label, int x, int y);
        ButtonWidget(string label, int x, int y, string backgroundPath);
        virtual ~ButtonWidget();

        virtual void Prepare(SDL_Renderer* renderer);

        virtual void Update();
        virtual void Draw();
        virtual void RefreshTexture();

        virtual void OnClick();

      protected:
        string _label;

        Texture* _background = nullptr;
        Texture* _renderTarget = nullptr;
        SDL_Texture* _fontTexture = nullptr;
        Font* _font;

        int _fontWidth = 0;
        int _fontHeight = 0;
    };
  }
}

#endif
