// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  int Renderer::DEFAULT_RENDERER_DRIVER = -1;

  Renderer::Renderer(SDL_Window* window) {
    renderer = SDL_CreateRenderer(window, DEFAULT_RENDERER_DRIVER, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
  }

  Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
  }

  void Renderer::Draw(SDL_Texture* texture, int width, int height, int x, int y) {
    SDL_Rect distance;
    distance.w = width;
    distance.h = height;
    distance.x = x;
    distance.y = y;

    SDL_RenderCopy(renderer, texture, NULL, &distance);
  }

  void Renderer::Clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
  }

  void Renderer::Render() {
    SDL_RenderPresent(renderer);
  }

  void Renderer::SetRenderTarget(Texture* texture) {
    texture->AsRenderTarget(renderer);
  }

  void Renderer::ClearRenderTarget() {
    SDL_SetRenderTarget(renderer, NULL);
  }
}
