#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "math.h"


#include "Components/Vector2f.hpp"
#include "Components/Entity.hpp"
#include "Components/Player.hpp"
#include "Components/Colors.hpp"
#include "Components/PinDefinitions.hpp"
#include "Components/Input.hpp"
#include "Components/Constants.hpp"
#include "Components/Obstacle.hpp"






Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
//display canvas
GFXcanvas1 frameBuffer(240,320);


//time variables for deltaTime;
double startTime = 0;
double endTime = 0;

double deltaTime = 0;

//enviropnment variables
uint16_t obstacleGapOffset = 20;

//entity variables
Vector2f obstacleMoveDir{0,1};
Vector2f playerUpDir{1,0};
Vector2f playerDownDir{-1,0};
uint16_t obstacleMoveSpeed = 40;


Player player{new Vector2f(40,80) , new Vector2f(20,40) , &tft};
Obstacle obstacle(new Vector2f(100,100) , new Vector2f(tft.width(),50) , &tft , player.GetScale()->x + obstacleGapOffset);
Vector2f endScreenPos{100,DISPLAY_HEIGHT - obstacle.GetScale()->y/2};
bool jumpButtonPress = false;
Input m_InputManager;
uint16_t playerSpeed = 20;





void DiagnosticTest()
{
    // read diagnostics (optional but can help debug problems)
  uint8_t x = tft.readcommand8(ILI9341_RDMODE);
  Serial.print("Display Power Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDMADCTL);
  Serial.print("MADCTL Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDPIXFMT);
  Serial.print("Pixel Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDIMGFMT);
  Serial.print("Image Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDSELFDIAG);
  Serial.print("Self Diagnostic: 0x"); Serial.println(x, HEX); 
}


void Update()
{
  //start logic loop

  //move player
  if(m_InputManager.GetButton(BUTTON_UP_PIN))
  {
    player.Translate(&playerUpDir , playerSpeed , deltaTime);
  }else
  {
      //player physics
      player.Translate(&playerDownDir , playerSpeed , deltaTime);
  }


  



  //move obstacle 
  obstacle.Translate( &obstacleMoveDir , 10 , deltaTime);

  if(obstacle.GetPosition()->y < (0 + (obstacle.GetScale()->y/2)))
  {
    obstacle.SetPosition(&endScreenPos);
    obstacle.SetGapYPos(random(70,150));
  }

  //end logic loop
}

void Draw()
{
    //start graphics loop


    frameBuffer.fillScreen(BLACK);

    obstacle.Draw(&frameBuffer);

    player.Draw(&frameBuffer);

    
    //end graphics loop
    tft.drawBitmap(0,0,frameBuffer.getBuffer(),tft.width(),tft.height(),WHITE,BLACK);

    
}

void Tick()
{
    /*    MAIN GAME LOOP
      1.Update logic;
      2.Update graphics;
      3.??
      4.Profit;

      target fps:over 9000 :)
  */

  
  
  //remember to convert deltaTime to seconds
  deltaTime = (endTime - startTime) / 1000;
  Serial.print("Delta Time : " );
  Serial.println(deltaTime);

  startTime = millis();  

  //main game loop goes here;

  Update();
  Draw();

  endTime = millis();
}

void setup() {

  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("SETUP START");

  tft.begin();
  tft.fillScreen(BLACK);
  tft.setRotation(0);

  if(ENABLE_DIAGNOSTIC == 1)
  {
    DiagnosticTest();
  }

  //control pins setup
  pinMode(BUTTON_DOWN_PIN,INPUT_PULLUP);
  pinMode(BUTTON_UP_PIN,INPUT_PULLUP);
  pinMode(BUTTON_LEFT_PIN,INPUT_PULLUP);
  pinMode(BUTTON_RIGHT_PIN,INPUT_PULLUP);

  obstacle.SetGapYPos(random(70,150));

}

void loop() 
{
  Tick();
}



