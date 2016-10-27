// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <string>
#include "Seeker.h"

#ifndef TEXTURE_H_
#define TEXTURE_H_

using std::string;

namespace Seeker {
  class Sprite : public IResource {
    public:
      Sprite(string path);
      ~Sprite();

      int Width;
      int Height;

      bool Prepare(SDL_Renderer* renderer);
      void Draw(int x, int y);
      void Destroy();

    private:
      SDL_Texture* texture = nullptr;
      SDL_Surface* surface = nullptr;
      string filename;
  };
}

#endif

