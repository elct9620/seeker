// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"
#include "SDL2/SDL_ttf.h"

#ifndef _UI_TEXT_WIDGET_H
#define _UI_TEXT_WIDGET_H

namespace Seeker {
  class Font;

  namespace UI {
    class TextWidget : public Widget {
      public:
        TextWidget(string text);
        TextWidget(string text, int x, int y);
        virtual ~TextWidget();

        virtual void Prepare(SDL_Renderer* renderer);

        virtual void Update();
        virtual void Draw();

        virtual void SetText(string text);

      private:
        Font* font = nullptr;
        SDL_Texture* texture = nullptr;

        string _text;
    };
  }
}

#endif
