// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "renderer.h"
#include "logger.h"
#include "window.h"
#include "texture.h"

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
