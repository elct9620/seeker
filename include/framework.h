// Copyright 2016 Zheng Xian Qiu

#include <SDL2/SDL.h>

#include "window.h"
#include "logger.h"

class Framework {
  public:
    static Framework* getInstance();

  private:
    Framework();
    static Framework *instance;
};


