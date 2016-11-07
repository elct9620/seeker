// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  Texture::Texture(string path) : filename(path), texture(nullptr) {
    Framework::Renderer()->Prepare<Texture>(this);
  }

  Texture::Texture(int width, int height, bool alpha) : Width(width), Height(height), alpha(alpha), texture(nullptr) {
    Framework::Renderer()->Prepare<Texture>(this);
    if(alpha) {
      SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    }
  }

  Texture::~Texture() {
    SDL_DestroyTexture(texture);
    texture = NULL;
  }

  void Texture::Prepare(SDL_Renderer* renderer) {
    if(filename.empty()) {
      texture = CreateTexture(renderer);
      return;
    }
    texture = CreateTextureFromSurface(renderer);
  }

  SDL_Texture* Texture::CreateTexture(SDL_Renderer* renderer) {
    return SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, Width, Height);
  }

  SDL_Texture* Texture::CreateTextureFromSurface(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(filename.c_str());

    if(!surface) {
      Logger::Error("Load image failed, %s", IMG_GetError());
      throw ResouceError(IMG_GetError());
    }

    if(texture) {
      SDL_DestroyTexture(texture);
      texture = NULL;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    Width = surface->w;
    Height = surface->h;

    SDL_FreeSurface(surface);
    return texture;
  }

  void Texture::Draw(int x, int y) {
    Draw(x, y, Width, Height);
  }

  void Texture::Draw(int x, int y, int w, int h) {
    Framework::Renderer()->Draw(texture, w, h, x, y);
  }

  void Texture::Destroy() {
    Resource<Texture>::Unload(ResourceKey(filename));
  }

  string Texture::ResourceKey(string filename) {
    return filename;
  }

  void Texture::AsRenderTarget(SDL_Renderer* renderer) {
    SDL_SetRenderTarget(renderer, texture);
  }
}
