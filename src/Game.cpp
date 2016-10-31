#include <SDL2/SDL.h>

#include "Seeker.h"

using namespace Seeker;

int main(int, char**) {

  // Bootstrap SDL
  if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0 ) {
    return 1;
  }

  if(TTF_Init() != 0) {
    return 1;
  }

  // Initialize Game
  IScript::Init<Script::Ruby>();
  Instance* instance = Framework::Instance()->createGame();

  if(instance == NULL) {
    Framework::Quit();
    return 1;
  }

  // Setup Game and Run
  IScript::Setup<Script::Ruby>();
  instance->Run();

  // Exit Game
  Framework::Quit();

  return 0;
}
