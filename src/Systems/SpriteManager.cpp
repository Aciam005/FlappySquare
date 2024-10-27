#include "SpriteManager.hpp"

Sprite* SpriteManager::GetSprite(SpriteType Type)
{
    Sprite* returnSprite = nullptr;
    switch(Type)
    {
        case Test_Sprite:   returnSprite = (Sprite*) malloc(sizeof(Sprite));

                            returnSprite->Size.x = TEST_WIDTH;
                            returnSprite->Size.y = TEST_HEIGHT;

                            returnSprite->SpriteBitmap = (uint8_t*) &m_Test_bits;

                            break;
    }

    return returnSprite;
}