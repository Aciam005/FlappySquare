#include "Systems/Game.hpp"



  //time variables for deltaTime;
  double m_StartTime = 0;
  double m_EndTime   = 0;
  double m_DeltaTime = 0;

  Game game;

void setup() {

  Serial.begin(9600);
  game.Start();
}

void loop() 
{
  //calculate DeltaTime (in seconds)
  m_DeltaTime = (m_EndTime - m_StartTime) / 1000;

  m_StartTime = millis();

  game.Tick(m_DeltaTime);

  delay(166);//target 60 fps
  m_EndTime = millis();
}



