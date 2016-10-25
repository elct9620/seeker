// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  Sprite::Sprite(string path, Renderer* _renderer) : texture(NULL), surface(NULL), filename(path) {
    renderer = _renderer == NULL ? Framework::getInstance()->getRenderer() : _renderer;

    surface = IMG_Load(path.c_str());

    width = 0;
    height = 0;

    if(surface == NULL) {
      Logger::Error("Failed to load texture, %s", IMG_GetError());
    }

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
    renderer->draw(texture, width, height, x, y);
  }

  void Sprite::release() {
    Resource<Sprite>::unload(filename);
  }
}
