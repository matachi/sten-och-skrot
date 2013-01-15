#include "../Artemis-Cpp/EntityProcessingSystem.h"
#include "../Artemis-Cpp/ComponentMapper.h"
#include "../components/position.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#ifndef SYSTEMS_SPRITERENDERSYSTEM_H_
#define SYSTEMS_SPRITERENDERSYSTEM_H_

class SpriteRenderSystem : public artemis::EntityProcessingSystem {
 public:
  SpriteRenderSystem();
  virtual void initialize();
  virtual void processEntity(artemis::Entity&);

 private:
  artemis::ComponentMapper<Position> positionMapper;
  ALLEGRO_BITMAP *bitmap;
};

#endif

