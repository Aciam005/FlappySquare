#include "Game.hpp"

#include "Components/Constants.hpp"
#include "Components/Colors.hpp"
#include "Components/SceneData.hpp"

#include "Systems/SceneManager.hpp"


#include "SPI.h"
#include "Adafruit_GFX.h"
#include "math.h"

//testing purposes,will be removed later

String scene1_Text[10] = 
{
    "Muie Furtuna",
    "-",
    "ETTI",
    "-",
    "NICUSOR DANICU",
    "-",
    "TEST",
    "-",
    "-",
    "MAI TESTAM",
};

//testing purposes,will be removed later
String scene2_Text[10]
{
    "SCENA 2",
    "SCENA 2",
    "SCENA 2",
    "SCENA 2",
    "SCENA 2",
    "SCENA 2",
    "SCENA 2",
    "SCENA 2",
    "SCENA 2",
    "SCENA 2",
};

//testing purposes,will be removed later
SceneData scene1{1,scene1_Text,10,nullptr,0};
SceneData scene2{2,scene2_Text,10,nullptr,0};

//testing purposes,will be removed later
bool test = false;

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

  m_SceneManager.PushSceneData(&scene1);
  m_SceneManager.PushSceneData(&scene2);

  m_SceneManager.LoadScene(1);

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
    //TODO:Find a way to write text without clearing the whole screen :(
    m_LocalScreenClearInterval += deltaTime;
    if(m_LocalScreenClearInterval > m_ScreenClearInterval)
    {
        m_Display.fillScreen(BLACK);
        m_SceneManager.RenderCurrentScene(&m_Renderer);
        m_LocalScreenClearInterval = 0;

        //testing purposes,will be removed later
        if(test)
        {
            test = !test;
            m_SceneManager.LoadScene(1);
        }else
        {
            test = !test;
            m_SceneManager.LoadScene(2);
        }
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
