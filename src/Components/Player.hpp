#ifndef PLAYER_H
#define PLAYER_H

#include "Components/Entity.hpp"
#include "Components/Colors.hpp"

class Player : public Entity
{
//methods
  public:
  Player(Vector2f* position,Vector2f* scale,Adafruit_ILI9341* display);
  void Draw(GFXcanvas1* buffer);
  void Translate(Vector2f* direction,float speed,double deltaTime);

  private:

  //member variables
  public:

  private:
  uint m_RoundedCornerRadius = 6;
};

#endif