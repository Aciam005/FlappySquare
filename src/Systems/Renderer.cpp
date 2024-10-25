#include "Renderer.hpp"
#include "Components/Colors.hpp"
#include "Components/Constants.hpp"
#include <Adafruit_GFX.h>

Renderer::Renderer(Adafruit_ILI9341 *tft)
{
    m_Display = tft;

    m_TextCanvas.setTextColor(WHITE);
    m_TextCanvas.setTextSize(m_TextSize);
    m_TextCanvas.setTextWrap(false);

    ClearTextScreen();
}

void Renderer::PushText(const String text)
{
    m_TextBuffer.push_back(text);


    while (m_TextBuffer.size() > MAX_TEXT_LINES)
    {
        //delete last element of queue until we have the max of MAX_TEXT_LINES elements
        m_TextBuffer.pop_front();
    }
}

void Renderer::PushSprite(Sprite *sprite)
{
    m_SpriteBuffer.push_back(sprite);


    while (m_SpriteBuffer.size() > MAX_SPRITES)
    {
        //delete last element of queue until we have the max of MAX_SPRITES elements
        Sprite* oldSprite = m_SpriteBuffer.front();
        m_SpriteBuffer.pop_front();
        free(oldSprite);
    }

}

void Renderer::RenderTextBuffer()
{   
    if(!m_TextBuffer.empty())
    {
        for(int i = 1;i <= m_TextBuffer.size();i++)
        {

            m_TextCanvas.setCursor(m_TextPaddingX, i * 8 + 4);

            String newString = m_TextBuffer.front();
            m_TextCanvas.print(newString);
            

            m_TextBuffer.pop_front();
            m_TextBuffer.push_back(newString);
        }
        //TODO:this works??
        //m_Display->fillScreen(BLACK);
    }

    m_Display->drawBitmap(0,0,m_TextCanvas.getBuffer(),240,160,WHITE);

}

void Renderer::RenderSpriteBuffer()
{
    Serial.println(m_SpriteBuffer.size());

    //draw a line to differentiate between the text and sprite(image) parts of the screen
    m_SpriteCanvas.drawFastHLine(0,0,240,WHITE);

    if(!m_SpriteBuffer.empty())
    {
        for(int i = 0;i <= m_SpriteBuffer.size();i++)
        {
            Sprite* newSprite = m_SpriteBuffer.front();

            m_SpriteCanvas.drawXBitmap(newSprite->Position.x,newSprite->Position.y,
                                      newSprite->SpriteBitmap,
                                      newSprite->Size.x,newSprite->Size.y,
                                      WHITE);

            m_SpriteBuffer.pop_front();
            m_SpriteBuffer.push_back(newSprite);
        }
    }

    m_Display->drawBitmap(0,161,m_SpriteCanvas.getBuffer(),240,160,WHITE);
}

void Renderer::ClearTextScreen()
{
    m_TextCanvas.fillScreen(BLACK);
}

void Renderer::ClearSpriteScreen()
{
    m_SpriteCanvas.fillScreen(BLACK);
}

void Renderer::Render()
{
    ClearTextScreen();
    RenderTextBuffer();
    

    ClearSpriteScreen();
    RenderSpriteBuffer();
    
}
