#include <Box2D/Box2D.h>
#include "../Artemis-Cpp/Component.h"
#include <string>

#ifndef COMPONENTS_BODY_H_
#define COMPONENTS_BODY_H_

class Body : public artemis::Component {
 public:
  Body(b2Body*);
  b2Body *getBody(void);
  void setBody(b2Body*);

 private:
  b2Body *b2body_;
};

#endif

