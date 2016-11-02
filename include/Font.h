// Copyright 2016 Zheng Xian Qiu

#pragma once

#include "Seeker.h"

#ifndef _FONT_H
#define _FONT_H

namespace Seeker {
  class Font : public IResource {
    public:
      Font(string path);
      ~Font();

      SDL_Surface* Draw(string text);
      void Destroy();

    private:
      string filename;
      TTF_Font *font;

  };
}

#endif
