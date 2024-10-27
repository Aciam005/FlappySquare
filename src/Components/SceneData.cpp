#include "SceneData.hpp"

SceneData::SceneData(uint8_t id, String* text , uint8_t textLineCount, Sprite* sprites , uint8_t spriteCount) : 
                             ID(id) , Text(text) , TextLineCount(textLineCount) , Sprites(sprites) , SpriteCount(spriteCount)
{}