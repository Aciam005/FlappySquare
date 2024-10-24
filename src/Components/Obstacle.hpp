#pragma once

#include <Components/Entity.hpp>

class Obstacle: public Entity
{
    //methods
    public:
    Obstacle(Vector2f* position, Vector2f* scale,Adafruit_ILI9341* display,uint16_t gapSize);
    void Draw(GFXcanvas1* buffer);
    void Translate(Vector2f* direction,float speed,double deltaTime);
    void SetPosition(Vector2f* newPosition);
    void SetGapYPos(uint16_t newYPos);


    //member variables
    private:
    /*
        @brief
        The size(in pixels) of the gap
    */
    uint16_t m_GapSize;
    /*
        @brief
        the Y-Axis position of the gap
    */
    uint16_t m_GapPosition;

};