#ifndef ENTITY_H
#define ENTITY_H

#include <Components/Vector2f.hpp>
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

class Entity
{
  protected:
    //position of the entity (in pixels)
    //by default,an Entity is created in the top LEFT corner of the screen
    Vector2f m_position{0,0};

    //position of the entity (in pixels)
    Vector2f m_scale{40,40};

    //the display the entity is rendered on
    Adafruit_ILI9341* tft = nullptr;

  public:
    Entity(Vector2f* position, Vector2f* scale,Adafruit_ILI9341* display);

    //Draw() method implemented by each derived class used in ... drawing the entity
    virtual void Draw(GFXcanvas1* buffer) = 0;
    virtual void Translate(Vector2f* direction,float speed,double deltaTime) = 0;

    //getters using the EVIL star >:((
    Vector2f* GetPosition();

    Vector2f* GetScale();
};

#endif