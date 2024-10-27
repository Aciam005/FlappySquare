#pragma once

#include <vector>

#include "Sprite.hpp"
#include "Constants.hpp"

class SceneData
{
    public:
    /*
        @brief
        NOTICE : DO NOT INITIATE A SCENE WITH THE INDEX OF 0!
        NOTICE : EMPTY LINES WILL BE IGNORED IN RENDERING!
    */
    SceneData(uint8_t id  , String* text  , uint8_t textLineCount  , Sprite* sprites , uint8_t spriteCount );

    private:

    public:
    /*
        Scene ID,used to find the scene
    */
    uint8_t ID;

    /*
        A pointer to an array of text lines that will be displayed
    */
    String* Text;
    uint8_t TextLineCount;

    /*
        A pointer to an array of Sprites that will be displayed
    */
    Sprite* Sprites;
    uint8_t SpriteCount;

    private:
};

