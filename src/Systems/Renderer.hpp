#pragma once
#include <Adafruit_GFX.h>
#include <deque>
#include <Adafruit_ILI9341.h>
#include "Components/Vector2.hpp"
#include "Components/Sprite.hpp"



class Renderer
{
    public:
    Renderer(Adafruit_ILI9341* tft);
    /*
        @brief
        Pushes text onto the Text Buffer
    */
    void PushText(String text);
    //TODO:Use a pointer to pass the String

    /*
        @brief
        Pushes a sprite onto the Sprite Buffer
    */
    void PushSprite(Sprite* sprite);

    private:
    /*
        @brief 
        Shows what's on the text buffer on the screen
    */
    void RenderTextBuffer();

    /*
        @brief 
        Shows what's on the sprite(image) buffer on the screen
    */
    void RenderSpriteBuffer();

    /*
        @brief
        Empties the text buffer
    */
    void ClearTextScreen();

    /*
        @brief
        Empties the sprite(image) buffer
    */
    void ClearSpriteScreen();


    //TODO:Add ability to remove a sprite by id
    //TODO:Maybe the sprites should be represented by smart pointers?

    public:
    /*
        @brief
        Renders both buffers,at once,onto the display
    */
    void Render();


    private:
    Adafruit_ILI9341* m_Display = nullptr;
    /*
        @brief
        The canvas that all text is written in
    */
    GFXcanvas1 m_TextCanvas{240,160};
    std::deque<String> m_TextBuffer;

    uint8_t m_TextSize = 1;
    uint8_t m_TextPaddingX = 10;

    /*
        @brief
        The canvas that all sprites are written in
    */
    GFXcanvas1 m_SpriteCanvas{240,160};
    std::deque<Sprite*> m_SpriteBuffer;
    

};