// Copyright 2016 Zheng Xian Qiu

#include "Seeker.h"

namespace Seeker {
  Sprite::Sprite(string path) {
    texture = Resource<Texture>::Load(path);
  }

  Sprite::~Sprite() {
    texture->Destroy();
  }

  void Sprite::Draw(int x, int y) {
    texture->Draw(x, y);
  }

  void Sprite::Destroy() {
  }
}
