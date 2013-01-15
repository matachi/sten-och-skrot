#include "../Artemis-Cpp/Component.h"

#ifndef COMPONENTS_VELOCITY_H_
#define COMPONENTS_VELOCITY_H_

class Velocity : public artemis::Component {
 public:
  Velocity(float, float);
  float getX(void);
  void setX(float);
  float getY(void);
  void setY(float);

 private:
  float x_, y_;
};

#endif //COMPONENTS_VELOCITY_H_

