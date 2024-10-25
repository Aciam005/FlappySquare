#include "Game.hpp"
#include "Components/Constants.hpp"
#include "Components/Colors.hpp"


#include "SPI.h"
#include "Adafruit_GFX.h"
#include "math.h"

Sprite* sprite;
Sprite* sprite1;
Sprite* sprite2;
Sprite* sprite3;
Sprite* sprite4;
Sprite* sprite5;

void Game::Start()
{
    if(ENABLE_DIAGNOSTIC)
    {
        DiagnosticTest();
    }

  m_Display.begin();
  m_Display.fillScreen(BLACK);
  m_Display.setRotation(0);

  //Input pins setup
  pinMode(BUTTON_DOWN_PIN,INPUT_PULLUP);
  pinMode(BUTTON_UP_PIN,INPUT_PULLUP);
  pinMode(BUTTON_LEFT_PIN,INPUT_PULLUP);
  pinMode(BUTTON_RIGHT_PIN,INPUT_PULLUP);


  //test text and sprite drawing systems

  DrawText("LINE 1");
  DrawText("LINE 2");
  DrawText("LINE 3");
  DrawText("LINE 4");
  DrawText("LINE 5");
  DrawText("LINE 6");
  DrawText("LINE 7");
  DrawText("LINE 8");
  DrawText("LINE 9");
  DrawText("LINE 10");
  DrawText("LINE 11");
  DrawText("LINE 12");
  DrawText("LINE 13");

  

  sprite = m_SpriteManager.GetSprite(SpriteType::Test_Sprite);
  sprite->Position.x = 50;
  sprite->Position.y = 50;

  sprite1 = m_SpriteManager.GetSprite(SpriteType::Test_Sprite);
  sprite1->Position.x = 100;
  sprite1->Position.y = 50;

  sprite2 = m_SpriteManager.GetSprite(SpriteType::Test_Sprite);
  sprite2->Position.x = 50;
  sprite2->Position.y = 100;

  sprite3 = m_SpriteManager.GetSprite(SpriteType::Test_Sprite);
  sprite3->Position.x = 100;
  sprite3->Position.y = 100;

  sprite4 = m_SpriteManager.GetSprite(SpriteType::Test_Sprite);
  sprite4->Position.x = 10;
  sprite4->Position.y = 10;

  sprite5 = m_SpriteManager.GetSprite(SpriteType::Test_Sprite);
  sprite5->Position.x = 50;
  sprite5->Position.y = 50;

  DrawSprite(sprite);
  DrawSprite(sprite1);
  DrawSprite(sprite2);
  DrawSprite(sprite3);
  DrawSprite(sprite4);
  DrawSprite(sprite5);

}

void Game::Tick(double deltaTime)
{
    //TODO:Add FPS counter
    Serial.println(esp_get_free_heap_size());
    Update(deltaTime);
    Draw  (deltaTime);
}

void Game::Update(double deltaTime)
{

}

void Game::Draw(double deltaTime)
{
    //TODO:Find a way to write good text without clearing the whole screen :(
    m_LocalScreenClearInterval += deltaTime;
    if(m_LocalScreenClearInterval > m_ScreenClearInterval)
    {
        m_Display.fillScreen(BLACK);
        m_Renderer.Render();
        m_LocalScreenClearInterval = 0;
    }
}

void Game::DrawText(String text)
{
    m_Renderer.PushText(text);
}

void Game::DrawSprite(Sprite *sprite)
{
    m_Renderer.PushSprite(sprite);
}

void Game::DiagnosticTest()
{
  // read diagnostics (optional but can help debug problems)
  uint8_t x = m_Display.readcommand8(ILI9341_RDMODE);
  Serial.print("Display Power Mode: 0x"); Serial.println(x, HEX);
  x = m_Display.readcommand8(ILI9341_RDMADCTL);
  Serial.print("MADCTL Mode: 0x"); Serial.println(x, HEX);
  x = m_Display.readcommand8(ILI9341_RDPIXFMT);
  Serial.print("Pixel Format: 0x"); Serial.println(x, HEX);
  x = m_Display.readcommand8(ILI9341_RDIMGFMT);
  Serial.print("Image Format: 0x"); Serial.println(x, HEX);
  x = m_Display.readcommand8(ILI9341_RDSELFDIAG);
  Serial.print("Self Diagnostic: 0x"); Serial.println(x, HEX); 
}
