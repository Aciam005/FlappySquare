#include "Obstacle.hpp"
#include "Colors.hpp"

Obstacle::Obstacle(Vector2f *position, Vector2f *scale, Adafruit_ILI9341 *display, uint16_t gapSize) 
: Entity::Entity(position,scale,display) , m_GapSize(gapSize) {}

void Obstacle::Draw(GFXcanvas1 *buffer)
{
    //draw the whole block
    buffer->fillRect(m_position.x - m_scale.x/2 , m_position.y - m_scale.y/2 , m_scale.x,m_scale.y,WHITE);

    //carve out a gap
    buffer->fillRect((m_position.x + m_GapPosition) - m_scale.x/2 , m_position.y - m_scale.y/2 , m_GapSize, m_scale.y , BLACK);
}

void Obstacle::Translate(Vector2f *direction, float speed, double deltaTime)
{
    this->m_position.y -= direction->y + speed * deltaTime;
}

void Obstacle::SetPosition(Vector2f *newPosition)
{
    this->m_position = *newPosition;
}

void Obstacle::SetGapYPos(uint16_t newYPos)
{
    this->m_GapPosition = newYPos;
}
