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
        
        m_Display->drawBitmap(0,0,m_TextCanvas.getBuffer(),240,160,WHITE);
        RenderSpriteBuffer();
    }

}

void Renderer::RenderSpriteBuffer()
{
    m_SpriteCanvas.drawFastHLine(0,0,240,WHITE);

    m_Display->drawBitmap(0,161,m_SpriteCanvas.getBuffer(),240,160,WHITE);
}

void Renderer::ClearTextScreen()
{
    m_TextCanvas.fillScreen(BLACK);
    m_Display->drawBitmap(0,0,m_TextCanvas.getBuffer(),240,160,WHITE);
}

void Renderer::Render()
{
    Serial.println("RENDER");
    ClearTextScreen();
    RenderTextBuffer();

    //TODO:Clear Sprite Buffer
    RenderSpriteBuffer();
}
