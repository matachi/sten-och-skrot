#include "entity_factory.h"
#include "components/sprite.h"
#include "components/velocity.h"
#include "components/position.h"
#include "components/body.h"

artemis::World *EntityFactory::world_;
b2World *EntityFactory::b2world_;

void EntityFactory::init(artemis::World *world, b2World *b2world) {
  world_ = world;
  b2world_ = b2world;
}

artemis::Entity *EntityFactory::createBox() {
  b2BodyDef bd;
  bd.type = b2_dynamicBody;
  bd.position.Set(0.0f, 10.0f);
  b2Body* body = b2world_->CreateBody(&bd);

  b2PolygonShape shape;
  shape.SetAsBox(0.5f, 0.5f);
  body->CreateFixture(&shape, 1.0f);

  artemis::EntityManager *em = world_->getEntityManager();
  artemis::Entity *box = &em->create();

  //box->addComponent(new Velocity(2,0));
  //box->addComponent(new Position(0,0));
  box->addComponent(new Sprite("sprite"));
  box->addComponent(new Body(body));
  box->refresh();

  return box;
}
