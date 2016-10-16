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

  Scene scene;
  Actor actor("../data/avatar.jpg", 100, 100);
  scene.addChild(&actor);

  instance->setScene(&scene);
  instance->run();

  Framework::quit();

  return 0;
}
