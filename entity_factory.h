#include <string>
#include <Box2D/Box2D.h>
#include "Artemis-Cpp/Component.h"
#include "Artemis-Cpp/Entity.h"
#include "Artemis-Cpp/World.h"

#ifndef ENTITYFACTORY_H_
#define ENTITYFACTORY_H_

class EntityFactory {
 public:
  static void init(artemis::World*, b2World*);
  static artemis::Entity *createBox(void);

 private:
  static artemis::World *world_;
  static b2World *b2world_;
};

#endif

