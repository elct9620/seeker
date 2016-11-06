// Copyright 2016 Zheng Xian Qiu
//

#pragma once

#include "Seeker.h"

#ifndef _TEXTURE_H
#define _TEXTURE_H

using std::string;

namespace Seeker {
  class Texture : public IResource {
    public:
      Texture(string path);
      ~Texture();

      int Width = 0;
      int Height = 0;

      void Prepare(SDL_Renderer* renderer);
      void Draw(int x, int y);
      void Draw(int x, int y, int w, int h);
      void Destroy();

      virtual string ResourceKey();

    private:
      string filename;
      SDL_Texture* texture = nullptr;
  };
}

#endif
