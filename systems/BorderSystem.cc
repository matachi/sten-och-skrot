#include "BorderSystem.h"

BorderSystem::BorderSystem() {
  addComponentType<Position>();
};

void BorderSystem::initialize() {
  positionMapper.init(*world);
};

void BorderSystem::processEntity(artemis::Entity &e) {
  Position *p = positionMapper.get(e);
  if (p->getX() > 640) {
    //std::cout << p->posX << std::endl;
    p->setX(0);
  }
};

