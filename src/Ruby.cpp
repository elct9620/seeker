// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  void Ruby::loadCore() {
    Script::Engine::instance()->defineModule<Script::Config>("Config", &Script::Config::init);
    Script::Engine::instance()->defineModule<Script::Game>("Game", &Script::Game::init);

    // Load Config Script
    Script::Engine::instance()->loadScript("../data/config.rb");
  }

  void Ruby::loadScript() {
    // TODO: Load all game script
  }
}
