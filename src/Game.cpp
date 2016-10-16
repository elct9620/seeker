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

  Sprite* sprite = Resource<Sprite>::load("../data/avatar.jpg");

  instance->getRenderer()->clear();
  sprite->draw(100, 100);
  instance->getRenderer()->render();

  instance->run();

  Resource<Sprite>::unload("../data/avatar.jpg");

  Framework::quit();

  return 0;
}
