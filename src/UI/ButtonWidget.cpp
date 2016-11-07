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
      _fontTexture = nullptr;

      if(!bgPath.empty()) {
        _background = Resource<Texture>::Load(bgPath);

        // TODO: Specify default width/height
        _width = _background->Width;
        _height = _background->Height;
      }

      if(!label.empty()) {
        _font = Resource<Font>::Load("../assets/fonts/NotoSansCJK/NotoSansTC-Regular.otf", 12);
        Framework::Renderer()->Prepare<ButtonWidget>(this);
      }

      Event::Instance()->Register(this);
    }

    ButtonWidget::~ButtonWidget() {
      if(_background) {
        _background->Destroy();
      }
    }

    void ButtonWidget::Prepare(SDL_Renderer* renderer) {
      SDL_Surface* surface = _font->Draw(_label);

      if(_fontTexture) {
        SDL_DestroyTexture(_fontTexture);
        _fontTexture = NULL;
      }

      _fontTexture = SDL_CreateTextureFromSurface(renderer, surface);
      if(!_fontTexture) {
        Logger::Debug(SDL_GetError());
      }
      _fontWidth = surface->w;
      _fontHeight = surface->h;

      SDL_FreeSurface(surface);
    }

    void ButtonWidget::Update() {
    }

    void ButtonWidget::Draw() {
      // TODO: Combine to one texture and render it
      if(_background) {
        _background->Draw(_x, _y);
      }

      if(_fontTexture) {
        int fontX = (_width / 2) - (_fontWidth / 2) + _x;
        int fontY = (_height / 2) - (_fontHeight / 2) + _y;
        Framework::Renderer()->Draw(_fontTexture, _fontWidth, _fontHeight, fontX, fontY);
      }
    }

    void ButtonWidget::OnClick() {
    }

  }
}
