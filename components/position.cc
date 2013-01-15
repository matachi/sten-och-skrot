#include "position.h"

Position::Position(float x, float y) {
  x_ = x;
  y_ = y;
}

float Position::getX() {
  return x_;
}

float Position::getY() {
  return y_;
}

void Position::setX(float x) {
  x_ = x;
}

void Position::setY(float y) {
  y_ = y;
}
