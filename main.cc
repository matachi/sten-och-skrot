#include <stdio.h>
#include <allegro5/allegro.h>
#include "Artemis-Cpp/World.h"
#include "Artemis-Cpp/Entity.h"
#include "Artemis-Cpp/Component.h"
#include "Artemis-Cpp/EntityProcessingSystem.h"
#include "Artemis-Cpp/ComponentMapper.h"
#include "Artemis-Cpp/SystemManager.h"
#include <cstdlib>
#include "components/velocity.h"
#include "components/position.h"
#include "components/sprite.h"
#include "systems/MovementSystem.h"
#include "systems/BorderSystem.h"
#include "systems/SpriteRenderSystem.h"
#include <Box2D/Box2D.h>

int main(int argc, char **argv){

  ALLEGRO_DISPLAY *display = NULL;
  ALLEGRO_KEYBOARD_STATE key_state;

  if(!al_init()) {
    fprintf(stderr, "failed to initialize allegro!\n");
    return -1;
  }

  display = al_create_display(640, 480);
  if(!display) {
    fprintf(stderr, "failed to create display!\n");
    return -1;
  }

  al_install_keyboard();
  al_clear_to_color(al_map_rgb(5,0,0));
  al_flip_display();

  artemis::World world;
  artemis::SystemManager * sm = world.getSystemManager();
  MovementSystem * movementsys = (MovementSystem*)sm->setSystem(new MovementSystem());
  BorderSystem * bordersys = (BorderSystem*)sm->setSystem(new BorderSystem());
  SpriteRenderSystem * spriterendersys = (SpriteRenderSystem*)sm->setSystem(new SpriteRenderSystem());
  artemis::EntityManager * em = world.getEntityManager();

  sm->initializeAll();

  //int const STARS = 10000;
  int const STARS = 10;

  //b2Body* b2World::CreateBody(const b2BodyDef* def);



  b2World *m_world;
  b2Vec2 gravity;
  gravity.Set(0.0f, -10.0f);
  m_world = new b2World(gravity);

  b2BodyDef bd;
  b2Body* ground = m_world->CreateBody(&bd);

  b2EdgeShape shape;
  shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
  ground->CreateFixture(&shape, 0.0f);


  artemis::Entity **array = (artemis::Entity**)(malloc(STARS * sizeof(artemis::Entity)));
  for (int i = 0; i < STARS; ++i) {
    array[i] = &em->create();
    array[i]->addComponent(new Velocity(std::rand() % 200 + 100,0));
    array[i]->addComponent(new Position(std::rand() % 640,std::rand() % 480));
    array[i]->refresh();
  }

  artemis::Entity & player = em->create();

  player.addComponent(new Velocity(2,0));
  player.addComponent(new Position(0,0));
  player.addComponent(new Sprite("sprite"));
  player.refresh();

  Position * comp = (Position*)player.getComponent<Position>();

  int counter = 0;

  while(true){
    ++counter;

    world.loopStart();
    world.setDelta(1/60.0f);
    movementsys->process();
    bordersys->process();
    spriterendersys->process();

    //al_clear_to_color(al_map_rgb(0,0,0));
    //al_lock_bitmap(al_get_backbuffer(display), ALLEGRO_PIXEL_FORMAT_ANY, 0);
    //for (int i = 0; i < STARS; ++i) {
    //  comp = (Position*)((array[i])->getComponent<Position>());
    //  al_put_pixel(comp->getX(), comp->getY(), al_map_rgb_f(1, 1, 1));
    //}
    //al_unlock_bitmap(al_get_backbuffer(display));
    al_flip_display();
    al_get_keyboard_state(&key_state);
    if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE))
      break;
  }

  std::cout << counter / al_get_time() << std::endl;

  al_destroy_display(display);

  return 0;
}
