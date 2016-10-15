#include <SDL2/SDL.h>

#include "Seeker.h"

using namespace Seeker;

int main(int, char**) {

  // Bootstrap SDL
  if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0 ) {
    return 1;
  }

  Framework::getInstance()->bootstrap();

  Sprite* sprite = Resource<Sprite>::load("../data/avatar.jpg");

  Framework::getInstance()->getRenderer()->clear();
  sprite->draw(100, 100);
  Framework::getInstance()->getRenderer()->render();

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

  Resource<Sprite>::unload("../data/avatar.jpg");

  Framework::quit();

  return 0;
}
