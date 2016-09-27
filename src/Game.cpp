#include <SDL2/SDL.h>

int main(int, char**) {
  if( SDL_Init(SDL_INIT_VIDEO) != 0 ) {
    return 1;
  }

  SDL_Window *win = SDL_CreateWindow("Seeker", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
  if(win == NULL) {
    SDL_DestroyWindow(win);
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
