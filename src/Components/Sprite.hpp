#pragma once

#include "Components/Vector2.hpp"
#include <Adafruit_GFX.h>

struct Sprite
{

    uint8_t* SpriteBitmap;

    /*
        @brief
        Position the sprite will be rendered on

        x->X coordinate of the top left corner
        y->X coordinate of the top left corner
    */
    Vector2<uint8_t> Position;

    /*
        @brief
        The size (width and height) of the sprite
    */
    Vector2<uint8_t> Size;
};
