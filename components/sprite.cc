#include "sprite.h"

Sprite::Sprite(std::string sprite) {
  sprite_ = sprite;
}

std::string Sprite::getSprite() {
  return sprite_;
}

void Sprite::setSprite(std::string sprite) {
  sprite_ = sprite;
}

