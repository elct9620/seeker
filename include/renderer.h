// Copyright 2016 Zheng Xian Qiu

#pragma once

#ifndef RENDERER_H_
#define RENDERER_H_

#include "framework.h"

class Renderer {
  public:
    Renderer(SDL_Window* window);
    ~Renderer();

    static int  DEFAULT_RENDERER_DRIVER;

  private:
    SDL_Renderer* renderer;
};

#endif
