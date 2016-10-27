// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  Framework::Framework() : currentGame(NULL) {
#ifdef DEBUG
    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_DEBUG);
#endif
  }

  Framework::~Framework() {
    delete currentGame;
    currentGame = NULL;
  }

  Framework* Framework::Instance() {
    if(instance) return instance;
    return new Framework();
  }

  Framework* Framework::instance = Framework::Instance();

  // Framework API

#ifdef VERSION
  string Framework::DEFAULT_WINDOW_NAME = CONCAT("Seeker Framework ", VERSION);
#else
  string Framework::DEFAULT_WINDOW_NAME = "Seeker Framework";
#endif

  void Framework::Quit() {
    delete instance;
  }

  // Alias Method
  Instance* Framework::Game() {
    return Instance()->GetGame();
  }

  Window* Framework::Window() {
    return Instance()->GetWindow();
  }

  Renderer* Framework::Renderer() {
    return Instance()->GetRenderer();
  }

  // Instance Method
  Instance* Framework::createGame() {
    try {
      if(currentGame) {
        delete currentGame;
      }

      currentGame = new class Instance;
      return currentGame;

    } catch (bool) {
      Logger::Error("Create game instance failed.");
    }
    return NULL;
  }

  Instance* Framework::GetGame() {
    return currentGame;
  }

  Window* Framework::GetWindow() {
    return currentGame->Window();
  }

  Renderer* Framework::GetRenderer() {
    return currentGame->Renderer();
  }
}
