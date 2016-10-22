// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace Script {
    void Ruby::loadCore() {
      namespace R = ::Seeker::Ruby;

      R::Engine* instance = R::Engine::instance();

      instance->defineModule<R::Config>("Config", &R::Config::init);
      instance->defineModule<R::Game>("Game", &R::Game::init);

      instance->defineClass<R::Scene>("Scene", &R::Scene::init);
      instance->defineClass<R::Actor>("Actor", &R::Actor::init);

      // Load Config Ruby
      instance->loadScript("../data/config.rb");
    }

    void Ruby::loadScript() {
      // TODO: Load all game script
      ::Seeker::Ruby::Engine* instance = ::Seeker::Ruby::Engine::instance();

      instance->loadScript("../data/main.rb");
    }
  }
}
