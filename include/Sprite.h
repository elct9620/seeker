// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <string>
#include "Seeker.h"

#ifndef TEXTURE_H_
#define TEXTURE_H_

using std::string;

namespace Seeker {
  class Sprite {
    public:
      Sprite(string path);
      ~Sprite();

      int Width;
      int Height;

      void Draw(int x, int y);
      void Destroy();

    private:
      Texture* texture;
      string filename;
  };
}

#endif

