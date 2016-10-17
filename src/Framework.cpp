// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  Framework::Framework() : currentGameInstance(NULL) {
#ifdef DEBUG
    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_DEBUG);
#endif
  }

  Framework::~Framework() {
    free(currentGameInstance);
  }

  Framework* Framework::getInstance() {
    if(instance != NULL) return instance;
    return new Framework();
  }

  Framework* Framework::instance = Framework::getInstance();

  // Framework API

#ifdef VERSION
  string Framework::DEFAULT_WINDOW_NAME = CONCAT("Seeker Framework ", VERSION);
#else
  string Framework::DEFAULT_WINDOW_NAME = "Seeker Framework";
#endif


  void Framework::quit() {
    free(instance);
  }

  Instance* Framework::createGameInstance() {
    try {
      currentGameInstance = new Instance;
      return currentGameInstance;
    } catch (bool) {
      Logger::Error("Create game instance failed.");
    }
    return NULL;
  }

  Window* Framework::getWindow() {
    return currentGameInstance->getWindow();
  }

  Renderer* Framework::getRenderer() {
    return currentGameInstance->getRenderer();
  }

}
