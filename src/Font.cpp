// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  Font::Font(string filename) : filename(filename) {
    // TODO: Support provide dynamic font size
    font = TTF_OpenFont(filename.c_str(), 16);

    if(!font) {
      Logger::Error("Load font failed, %s", TTF_GetError());
      throw ResouceError(TTF_GetError());
    }
  }

  Font::~Font() {
    TTF_CloseFont(font);
    font = NULL;
  }

  SDL_Surface* Font::Draw(string text) {
    // TODO: Support specify font color
    SDL_Color color = {255, 255, 255, 255};
    return TTF_RenderUTF8_Solid(font, text.c_str(), color);
  }

  void Font::Destroy() {
    Resource<Font>::Unload(filename);
  }
}
