#include <SDL2/SDL.h>

#include "framework.h"

int main(int, char**) {

  // Bootstrap SDL
  if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0 ) {
    return 1;
  }

  Window window;

  if(window.create("Seeker") == false) {
    window.destroy();
    SDL_Quit();
     return 1;
  }

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

  return 0;
}
