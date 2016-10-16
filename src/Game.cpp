#include <SDL2/SDL.h>

#include "Seeker.h"

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

  Actor actor("../data/avatar.jpg", 100, 100);

  instance->getRenderer()->clear();
  actor.update(0);
  instance->getRenderer()->render();

  instance->run();

  Framework::quit();

  return 0;
}
