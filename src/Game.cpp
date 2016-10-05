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

  instance->run();

  Framework::quit();

  return 0;
}
