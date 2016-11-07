// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  Font::Font(string filename, int size) : filename(filename), size(size) {
    font = TTF_OpenFont(filename.c_str(), size);

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

    // NOTICE: Slow render, but with antialiasing
    return TTF_RenderUTF8_Blended(font, text.c_str(), color);
  }

  void Font::Destroy() {
    Resource<Font>::Unload(ResourceKey(filename, size));
  }

  string Font::ResourceKey(string filename, int size) {
    string sizeInString = std::to_string(size);
    return string(filename + "@" + sizeInString);
  }
}
