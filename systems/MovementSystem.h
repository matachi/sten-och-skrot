#include "../Artemis-Cpp/EntityProcessingSystem.h"
#include "../Artemis-Cpp/ComponentMapper.h"
#include "../components/velocity.h"
#include "../components/position.h"

#ifndef SYSTEMS_MOVEMENTSYSTEM_H_
#define SYSTEMS_MOVEMENTSYSTEM_H_

class MovementSystem : public artemis::EntityProcessingSystem {
 public:
  MovementSystem();
  virtual void initialize();
  virtual void processEntity(artemis::Entity&);

 private:
  artemis::ComponentMapper<Velocity> velocityMapper;
  artemis::ComponentMapper<Position> positionMapper;
};

#endif

