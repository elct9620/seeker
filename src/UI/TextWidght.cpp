// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace UI {
    TextWidget::TextWidget(string text) {
      TextWidget(text, x, y);
      Framework::Renderer()->Prepare<TextWidget>(this);
    }

    TextWidget::TextWidget(string text, int _x, int _y) : _text(text) {
      x = _x;
      y = _y;

      // TODO: Provide custom font options
      // TODO: Prevent direct specify font path
      font = Resource<Font>::Load("../assets/fonts/OpenSans/OpenSans-Regular.ttf");
    }

    TextWidget::~TextWidget() {
      SDL_DestroyTexture(texture);
      font->Destroy();
    }

    void TextWidget::Prepare(SDL_Renderer* renderer) {
      SDL_Surface* surface = font->Draw(_text);

      if(texture) {
        SDL_DestroyTexture(texture);
        texture = NULL;
      }

      texture = SDL_CreateTextureFromSurface(renderer, surface);
      SDL_QueryTexture(texture, NULL, NULL, &_TextWidth, &_TextHeight);

      SDL_FreeSurface(surface);
    }

    void TextWidget::Update() {
    }

    void TextWidget::Draw() {
      int drawX = 0, drawY = 0;

      if(parent) {
        drawX = parent->X();
        drawY = parent->Y();
      }

      drawX += x;
      drawY += y;

      Framework::Renderer()->Draw(texture, _TextWidth, _TextWidth, drawX, drawY);
    }

    void TextWidget::SetText(string text) {
      _text = text;
      Framework::Renderer()->Prepare<TextWidget>(this);
    }
  }
}
