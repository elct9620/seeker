// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  Sprite::Sprite(string path) : texture(NULL), surface(NULL), filename(path) {
    surface = IMG_Load(path.c_str());

    Width = 0;
    Height = 0;

    if(surface == NULL) {
      Logger::Error("Failed to load texture, %s", IMG_GetError());
    }

    Renderer* renderer = Framework::Renderer();
    renderer->CreateSprite(this);
  }

  Sprite::~Sprite() {
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
  }

  bool Sprite::Prepare(SDL_Renderer* renderer) {
    if(texture) return true;

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(texture == NULL) {
      Logger::Error("Failed to initialize texture, %s", SDL_GetError());
      return false;
    }

    SDL_QueryTexture(texture, NULL, NULL, &Width, &Height);

    return true;
  }

  void Sprite::Draw(int x, int y) {
    Renderer* renderer = Framework::Renderer();
    renderer->Draw(texture, Width, Height, x, y);
  }

  void Sprite::Destroy() {
    Resource<Sprite>::Unload(filename);
  }
}
