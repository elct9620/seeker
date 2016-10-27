// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  Sprite::Sprite(string path) : texture(NULL), surface(NULL), filename(path) {
    surface = IMG_Load(path.c_str());

    width = 0;
    height = 0;

    if(surface == NULL) {
      Logger::Error("Failed to load texture, %s", IMG_GetError());
    }

    Renderer* renderer = Framework::getInstance()->getRenderer();
    renderer->createSprite(this);
  }

  Sprite::~Sprite() {
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
  }

  bool Sprite::prepare(SDL_Renderer* renderer) {
    if(texture) return true;

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(texture == NULL) {
      Logger::Error("Failed to initialize texture, %s", SDL_GetError());
      return false;
    }

    SDL_QueryTexture(texture, NULL, NULL, &width, &height);

    return true;
  }

  void Sprite::draw(int x, int y) {
    Renderer* renderer = Framework::getInstance()->getRenderer();
    renderer->draw(texture, width, height, x, y);
  }

  void Sprite::release() {
    Resource<Sprite>::unload(filename);
  }
}
