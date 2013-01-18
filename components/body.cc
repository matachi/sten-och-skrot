#include "body.h"

Body::Body(b2Body *b2body) {
  b2body_ = b2body;
}

b2Body *Body::getBody() {
  return b2body_;
}

void Body::setBody(b2Body *b2body) {
  b2body_ = b2body;
}

