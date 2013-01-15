#include "SpriteRenderSystem.h"
//#include <stdio.h>

SpriteRenderSystem::SpriteRenderSystem() {
  addComponentType<Position>();
};

//virtual void initialize() {
void SpriteRenderSystem::initialize() {
  positionMapper.init(*world);
  al_init_image_addon();
  bitmap = al_load_bitmap("image.png");
  //bitmap = al_create_bitmap(10, 20);
  //bit
};

//virtual void processEntity(artemis::Entity &e) {
void SpriteRenderSystem::processEntity(artemis::Entity &e) {
  //al_draw_bitmap(bitmap, 0, 0, 0);
  al_draw_scaled_bitmap(bitmap, 0, 0, 10, 10, 0, 0, 100, 100, 0);
};
