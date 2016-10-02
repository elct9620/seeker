// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Renderer.h"
#include "Logger.h"
#include "Window.h"
#include "Texture.h"

#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

class Framework {
  public:
    static Framework* getInstance();

  private:
    Framework();
    static Framework *instance;
};

#endif
