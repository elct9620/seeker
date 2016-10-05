#include <SDL2/SDL.h>

#include "Framework.h"

using namespace Seeker;

int main(int, char**) {

  // Bootstrap SDL
  if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0 ) {
    return 1;
  }

  Instance* instance = Framework::getInstance()->createGameInstance();

  if(instance == NULL) {
    Framework::quit();
    return 1;
  }

  Texture texture("../data/avatar.jpg");

  instance->getRenderer()->clear();
  texture.draw(100, 100);
  instance->getRenderer()->render();

  bool quit = false;
  SDL_Event ev;
  while(!quit) {
    while(SDL_PollEvent(&ev)) {
      switch(ev.type) {
        case SDL_QUIT:
        case SDL_KEYDOWN:
        case SDL_MOUSEBUTTONDOWN:
          quit = true;
          break;
      }
    }
  }

  Framework::quit();

  return 0;
}
