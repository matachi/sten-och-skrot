#include "../Artemis-Cpp/Component.h"

#ifndef COMPONENTS_POSITION_H_
#define COMPONENTS_POSITION_H_

class Position : public artemis::Component {
 public:
  Position(float, float);
  float getX(void);
  void setX(float);
  float getY(void);
  void setY(float);

 private:
  float x_, y_;
};

#endif //COMPONENTS_POSITION_H_

