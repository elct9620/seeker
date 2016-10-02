// Copyright 2016 Zheng Xian Qiu

#include "Framework.h"

Framework::Framework() {
#ifdef DEBUG
  SDL_LogSetAllPriority(SDL_LOG_PRIORITY_DEBUG);
#endif
}

Framework* Framework::getInstance() {
  if(instance != NULL) return instance;
  return new Framework();
}

Framework* Framework::instance = Framework::getInstance();
