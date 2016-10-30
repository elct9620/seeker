// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  Window::Window() : currentWindow(NULL), renderer(NULL) {
  }

  Window::~Window() {
    SDL_DestroyWindow(currentWindow);

    delete renderer;
  }

  // Display Information

  int Window::DISPLAY_INDEX = 0;
  bool Window::displayModeLoaded = false;
  SDL_DisplayMode Window::displayMode;

  int Window::DisplayWidth() {
    LoadDisplayMode();
    return displayMode.w;
  }

  int Window::DisplayHeight() {
    LoadDisplayMode();
    return displayMode.h;
  }

  void Window::LoadDisplayMode(bool reload) {
    if(!displayModeLoaded || reload) {
      if(SDL_GetCurrentDisplayMode(DISPLAY_INDEX, &displayMode) != 0) {
        displayModeLoaded = false;
      }
      displayModeLoaded = true;
    }
  }

  // Window Manager
  bool Window::Create(string title, bool hide) {
    return Create(title, DisplayWidth(), DisplayHeight(), hide);
  }

  bool Window::Create(string title, int _width, int _height, bool hide) {
    uint flags = hide ? 0 : SDL_WINDOW_SHOWN;
    flags = flags | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_INPUT_GRABBED;

    // Ensure get correct window resolution
    LoadDisplayMode(true);
    _width  = _width  > 0 ? _width  : DisplayWidth();
    _height = _height > 0 ? _height : DisplayHeight();

    currentWindow = SDL_CreateWindow(title.c_str(), 0, 0, _width, _height, flags);
    if(currentWindow == NULL) {
      SDL_DestroyWindow(currentWindow);
      return false;
    }

    Logger::Info("Initialize window with %dx%dpx resolution.", DisplayWidth(), DisplayHeight());

    return true;
  }

  void Window::Destroy() {
    SDL_DestroyWindow(currentWindow);
  }

  Renderer* Window::Renderer() {
    if(renderer == NULL) {
      renderer = new class Renderer(currentWindow);
    }

    return renderer;
  }
}
