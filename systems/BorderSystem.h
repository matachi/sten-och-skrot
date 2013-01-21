#include <Artemis-Cpp/EntityProcessingSystem.h>
#include <Artemis-Cpp/ComponentMapper.h>
#include "../components/position.h"

#ifndef SYSTEMS_BORDERSYSTEM_H_
#define SYSTEMS_BORDERSYSTEM_H_

class BorderSystem : public artemis::EntityProcessingSystem {
 public:
  BorderSystem();
  virtual void initialize();
  virtual void processEntity(artemis::Entity &);

 private:
    artemis::ComponentMapper<Position> positionMapper;
};

#endif

