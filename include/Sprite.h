// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <string>
#include "Seeker.h"

#ifndef TEXTURE_H_
#define TEXTURE_H_

using std::string;

namespace Seeker {
  class Renderer;
  class Sprite : public IResource {
    public:
      Sprite(string path, Renderer* _renderer = NULL);
      ~Sprite();

      int width;
      int height;

      bool prepare(SDL_Renderer* renderer);
      void draw(int x, int y);
      void release();

    private:
      SDL_Texture* texture = nullptr;
      SDL_Surface* surface = nullptr;
      Renderer* renderer = nullptr;
      string filename;
  };
}

#endif

