#pragma once
#include <Adafruit_GFX.h>
#include <deque>
#include <Adafruit_ILI9341.h>

class Renderer
{
    public:
    Renderer(Adafruit_ILI9341* tft);
    /*
        @brief
        Pushes text onto the Text Buffer
    */
    void PushText(String text);

    private:
    void RenderTextBuffer();
    void RenderSpriteBuffer();
    void ClearTextScreen();




    public:
    void Render();


    private:
    Adafruit_ILI9341* m_Display = nullptr;
    /*
        @brief
        The canvas that all text is written in
    */
    GFXcanvas1 m_TextCanvas{240,160};

    /*
        @brief
        The canvas that all sprites are written in
    */
    GFXcanvas1 m_SpriteCanvas{240,160};
    std::deque<String> m_TextBuffer;
    uint8_t m_TextSize = 1;
    uint8_t m_TextPaddingX = 10;
};