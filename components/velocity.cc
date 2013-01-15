#include "velocity.h"

Velocity::Velocity(float x, float y) {
  x_ = x;
  y_ = y;
}

float Velocity::getX() {
  return x_;
}

float Velocity::getY() {
  return y_;
}

void Velocity::setX(float x) {
  x_ = x;
}

void Velocity::setY(float y) {
  y_ = y;
}
