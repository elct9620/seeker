// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  namespace Script {
    void Ruby::LoadCore() {
      namespace R = Seeker::Ruby;

      R::Engine* instance = R::Engine::Instance();

      instance->DefineModule<R::Config>("Config", &R::Config::init);
      instance->DefineModule<R::Game>("Game", &R::Game::init);

      instance->DefineClass<R::Scene>("Scene", &R::Scene::init);
      instance->DefineClass<R::Actor>("Actor", &R::Actor::init);

      // Load Config Ruby
      instance->LoadScript("../data/config.rb");
    }

    void Ruby::LoadScript() {
      // TODO: Load all game script
      Seeker::Ruby::Engine* instance = Seeker::Ruby::Engine::Instance();

      instance->LoadScript("../data/main.rb");
    }
  }
}
