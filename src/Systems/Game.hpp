#pragma once
#include <Adafruit_ILI9341.h>
#include <Components/PinDefinitions.hpp>
#include "Systems/Renderer.hpp"
#include "Systems/SpriteManager.hpp"

class Game
{
    public:
    /*
        @brief
        Performs initial operations for the game to start
    */
    void Start();

    /*
        @brief 
        Main game loop
    */
    void Tick(double deltaTime);

    private:
    /*
        @brief 
        Logic loop
    */
    void Update(double deltaTime);

    /*
        @brief 
        Graphics loop
    */
    void Draw(double deltaTime);

    /*
        @brief
        Draw text to the screen
    */
    void DrawText(String text);

    /*
        @brief
        Draw a sprite to the screen
    */
    void DrawSprite(Sprite* sprite);

    /*
        @brief
        Start a quick diagnostic test for the display
    */
     void DiagnosticTest();

    public:

    private:
    Adafruit_ILI9341 m_Display = Adafruit_ILI9341(TFT_CS, TFT_DC);

    /*
        @brief
        The Renderer handles all rendering to the tft display
    */
    Renderer m_Renderer{&m_Display};

    /*
        @brief
        The SpriteManager stores all sprite data (as unsigned char arrays)
    */
    SpriteManager m_SpriteManager;

    /*
        @brief
        How often(in s) should the screen be cleared?
    */
    uint8_t m_ScreenClearInterval = 1;
    double m_LocalScreenClearInterval = 0;
};