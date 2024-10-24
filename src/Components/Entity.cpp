#include "Entity.hpp"

Entity::Entity(Vector2f* position, Vector2f* scale , Adafruit_ILI9341* display) : m_position(position) , m_scale(scale) , tft(display) {}

Vector2f* Entity:: GetPosition()
    {
      return &m_position;
    } 

Vector2f* Entity:: GetScale()
    {
      return &m_scale;
    } 