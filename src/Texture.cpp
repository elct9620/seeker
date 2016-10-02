// Copyright 2016 Zheng Xian Qiu

#include "Texture.h"

namespace Seeker {
  Texture::Texture(string path, Renderer* _renderer) : texture(NULL), surface(NULL) {
    renderer = _renderer == NULL ? Framework::getInstance()->getRenderer() : _renderer;

    surface = IMG_Load(path.c_str());

    width = 0;
    height = 0;

    if(surface == NULL) {
      Logger::Error("Failed to load texture, %s", IMG_GetError());
    }

    renderer->createTexture(this);
  }

  Texture::~Texture() {
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
  }

  bool Texture::prepare(SDL_Renderer* renderer) {
    if(texture) return true;

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(texture == NULL) {
      Logger::Error("Failed to initialize texture, %s", SDL_GetError());
      return false;
    }

    SDL_QueryTexture(texture, NULL, NULL, &width, &height);

    return true;
  }

  void Texture::draw(int x, int y) {
    renderer->draw(texture, width, height, x, y);
  }
}
