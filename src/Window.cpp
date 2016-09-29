// Copyright 2016 Zheng Xian Qiu

#include "framework.h"

Window::Window() {
}

// Display Information

int Window::DISPLAY_INDEX = 0;
bool Window::displayModeLoaded = false;
SDL_DisplayMode Window::displayMode;

int Window::getDisplayWidth() {
  loadDisplayMode();
  return displayMode.w;
}

int Window::getDisplayHeight() {
  loadDisplayMode();
  return displayMode.h;
}

void Window::loadDisplayMode(bool reload) {
  if(!displayModeLoaded || reload) {
    if(SDL_GetCurrentDisplayMode(DISPLAY_INDEX, &displayMode) != 0) {
      displayModeLoaded = false;
    }
    displayModeLoaded = true;
  }
}

// Window Manager
bool Window::create(string title, bool hide) {
  uint flags = hide ? 0 : SDL_WINDOW_SHOWN;
  flags = flags | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_INPUT_GRABBED;

  currentWindow = SDL_CreateWindow(title.c_str(), 0, 0, getDisplayWidth(), getDisplayHeight(), flags);
  if(currentWindow == NULL) {
    SDL_DestroyWindow(currentWindow);
    return false;
  }

  Logger::Info("Initialize window with %dx%dpx resolution.", getDisplayWidth(), getDisplayHeight());

  return true;
}

void Window::destroy() {
  SDL_DestroyWindow(currentWindow);
}
