#include "Player.hpp"

Player::Player(Vector2f *position, Vector2f *scale, Adafruit_ILI9341 *display) : Entity(position, scale, display)
{
}

void Player::Draw(GFXcanvas1 *buffer)
{
  int16_t xPos = m_position.x;
  int16_t yPos = m_position.y;

  // handle edge cases on x axis
  if ((xPos - m_scale.x / 2) < 0)
  {
    xPos = m_scale.x / 2;
  }
  if ((xPos + m_scale.x / 2) > tft->width())
  {
    xPos = tft->width() - m_scale.x / 2;
  }

  // handle edge cases on y axis
  if ((yPos - m_scale.y / 2) < 0)
  {
    yPos = m_scale.y / 2;
  }
  if ((yPos + m_scale.y / 2) > tft->height())
  {
    yPos = tft->height() - m_scale.y / 2;
  }

  m_position.x = xPos;
  m_position.y = yPos;

  // when drawing keep in mind that the display starts drawing from the top left of the sprite

  buffer->drawRoundRect(m_position.x - m_scale.x / 2, m_position.y - m_scale.y / 2, m_scale.x, m_scale.y, m_RoundedCornerRadius, WHITE);
}

void Player::Translate(Vector2f *direction, float speed, double deltaTime)
{
  // first,assume no edge cases
  int16_t xPos = m_position.x + direction->x * speed * deltaTime;
  int16_t yPos = m_position.y + direction->y * speed * deltaTime;

  // handle edge cases on x axis
  if ((xPos - m_scale.x / 2) < 0)
  {
    xPos = 0;
  }
  if ((xPos + m_scale.x / 2) > tft->width())
  {
    xPos = tft->width() - m_scale.x / 2;
  }

  // handle edge cases on y axis
  if ((yPos - m_scale.y / 2) < 0)
  {
    yPos = 0;
  }

  if ((yPos + m_scale.y / 2) > tft->height())
  {
    yPos = tft->height();
  }

  m_position.x = (float)xPos;
  m_position.y = (float)yPos;
}