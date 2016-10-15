// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <string>
#include "Seeker.h"

#ifndef TEXTURE_H_
#define TEXTURE_H_

using std::string;

namespace Seeker {
  class Renderer;
  class Texture : public IResource {
    public:
      Texture(string path, Renderer* _renderer = NULL);
      ~Texture();

      int width;
      int height;

      bool prepare(SDL_Renderer* renderer);
      void draw(int x, int y);

    private:
      SDL_Texture* texture;
      SDL_Surface* surface;
      Renderer* renderer;
  };
}

#endif

