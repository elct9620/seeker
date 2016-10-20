#include <SDL2/SDL.h>

#include "Seeker.h"

using namespace Seeker;

int main(int, char**) {

  // Bootstrap SDL
  if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0 ) {
    return 1;
  }

  // TODO: Put int one file to specify all script/core should be load
  Script::Engine::instance()->defineModule<Script::Config>("Config", &Script::Config::init);
  Script::Engine::instance()->defineModule<Script::Game>("Game", &Script::Game::init);

  Script::Engine::instance()->loadScript("../data/config.rb");

  Instance* instance = Framework::getInstance()->createGameInstance();

  if(instance == NULL) {
    Framework::quit();
    return 1;
  }

  // TODO: Run before load all script
  instance->run();

  Framework::quit();

  return 0;
}
