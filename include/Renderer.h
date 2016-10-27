// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"

#ifndef RENDERER_H_
#define RENDERER_H_

namespace Seeker {
  class Sprite;
  class Renderer {
    public:
      Renderer(SDL_Window* window);
      ~Renderer();

      static int DEFAULT_RENDERER_DRIVER;

      template<class T> void Prepare(T* klass) {
        klass->Prepare(renderer);
      };
      void Draw(SDL_Texture* texture, int width, int height, int x, int y);
      void Render();
      void Clear();

    private:
      SDL_Renderer* renderer = nullptr;
  };
}

#endif
