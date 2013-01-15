#include "MovementSystem.h"

MovementSystem::MovementSystem() {
  addComponentType<Velocity>();
  addComponentType<Position>();
};

//virtual void initialize() {
void MovementSystem::initialize() {
  velocityMapper.init(*world);
  positionMapper.init(*world);
};

//virtual void processEntity(artemis::Entity &e) {
void MovementSystem::processEntity(artemis::Entity &e) {
  positionMapper.get(e)->setX(positionMapper.get(e)->getX() + velocityMapper.get(e)->getX() * world->getDelta());
  positionMapper.get(e)->setY(positionMapper.get(e)->getY() + velocityMapper.get(e)->getY() * world->getDelta());
};
