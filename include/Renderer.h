// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"

#ifndef RENDERER_H_
#define RENDERER_H_

namespace Seeker {
  class Texture;
  class Renderer {
    public:
      Renderer(SDL_Window* window);
      ~Renderer();

      static int DEFAULT_RENDERER_DRIVER;

      void createTexture(Texture* texture);
      void draw(SDL_Texture* texture, int width, int height, int x, int y);
      void render();
      void clear();

    private:
      SDL_Renderer* renderer;
  };
}

#endif
