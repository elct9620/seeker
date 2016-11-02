// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace UI {
    TextWidget::TextWidget(string text) {
      TextWidget(text, 0, 0);
    }

    TextWidget::TextWidget(string text, int x, int y) : Widget(x, y), _text(text) {
      // TODO: Provide custom font options
      // TODO: Prevent direct specify font path
      font = Resource<Font>::Load("../assets/fonts/NotoSansCJK/NotoSansTC-Regular.otf");
      Framework::Renderer()->Prepare<TextWidget>(this);
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
      if(!texture) {
        Logger::Debug(SDL_GetError());
      }
      _width = surface->w;
      _height = surface->h;

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

      drawX += _x;
      drawY += _y;

      Framework::Renderer()->Draw(texture, _width, _height, drawX, drawY);
    }

    void TextWidget::SetText(string text) {
      _text = text;
      Framework::Renderer()->Prepare<TextWidget>(this);
    }
  }
}
