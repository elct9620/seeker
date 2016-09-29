// Copyright 2016 Zheng Xian Qiu

#include "renderer.h"

int Renderer::DEFAULT_RENDERER_DRIVER = -1;

Renderer::Renderer(SDL_Window* window) {
  renderer = SDL_CreateRenderer(window, DEFAULT_RENDERER_DRIVER, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
}

Renderer::~Renderer() {
  SDL_DestroyRenderer(renderer);
}
