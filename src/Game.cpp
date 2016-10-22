#include <SDL2/SDL.h>

#include "Seeker.h"

using namespace Seeker;

int main(int, char**) {

  // Bootstrap SDL
  if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0 ) {
    return 1;
  }

  // Initialize Game
  IScript::init<Script::Ruby>();
  Instance* instance = Framework::getInstance()->createGameInstance();

  if(instance == NULL) {
    Framework::quit();
    return 1;
  }

  // Setup Game and Run
  IScript::setup<Script::Ruby>();
  instance->run();

  // Exit Game
  Framework::quit();

  return 0;
}
