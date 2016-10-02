// Copyright 2016 Zheng Xian Qiu

#include "Framework.h"

namespace Seeker {
  Framework::Framework() : currentWindow(NULL), currentRenderer(NULL) {
#ifdef DEBUG
    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_DEBUG);
#endif
  }

  Framework::~Framework() {
    free(currentWindow);
    free(currentRenderer);
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

  void Framework::bootstrap() {
    Window* window = new Window;
    if(window->create(DEFAULT_WINDOW_NAME) == false) {
      // TODO: Must return exception to alert developer
      Logger::Error("Bootstrap framework failed!");
      return;
    }

    use(window);
    use(window->getRenderer());

    Logger::Info("Framework is ready!");
  }

  void Framework::quit() {
    free(instance);
  }

  Renderer* Framework::getRenderer() {
    return currentRenderer;
  }

  Window* Framework::getWindow() {
    return currentWindow;
  }
}
