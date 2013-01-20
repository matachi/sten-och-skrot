#include <Artemis-Cpp/Component.h>
#include <string>

#ifndef COMPONENTS_SPRITE_H_
#define COMPONENTS_SPRITE_H_

class Sprite : public artemis::Component {
 public:
  Sprite(std::string);
  std::string getSprite(void);
  void setSprite(std::string);

 private:
  std::string sprite_;
};

#endif

