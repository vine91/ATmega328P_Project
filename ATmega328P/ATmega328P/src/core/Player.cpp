/*
 *    NOTE        - Player.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.20
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "Player.hpp"


/*----------------------------------------//
              Running Player
//----------------------------------------*/

void Player::running(void)
{

  if (Frame::oneTick == 1)
  {
    m_IsDrawed = false;
  }

  if (m_IsDrawed == false)
  {
    for (int i=0; i<6; i++)
    {

      if (Frame::sixFrames == i)
      {
        draw(40, 140, 40, 40, charRun, i, BLACK, MAROON, RED, WHITE);
        m_IsDrawed = true;
      }

    }
  }

}

/*----------------------------------------//
              Jumping Player
//----------------------------------------*/

void Player::jumping(void)
{

  if (Frame::oneTick == 1)
  {

    if (m_IsUp == true)
    {
      m_JumpHeight += 6;

      if (m_JumpHeight >= 50)
      {
        m_JumpTemp ++;
        m_JumpHeight -= 6;

        if (m_JumpTemp == 4)
        {
          m_JumpHeight += 6;
          m_IsUp = false;
        }
      }
    }

    else
    {
      m_JumpHeight -= 6;

      if (m_JumpHeight <= 0)
      {
        clear(40, 140 - 25, 40, 25, BLACK);
        SW::interrupt0 = OFF;
        m_IsJump = false;
        m_IsReset = false;
        return;
      }
    }

    m_IsDrawed = false;

  }

  if (m_IsDrawed == false)
  {
    if (m_IsUp == true)
    {
      for (int i=0; i<4; i++)
      {
        if (Frame::fourFrames == i)
        {
          draw(40, 122 - m_JumpHeight, 32, 50, charUp, i, BLACK, MAROON, RED, WHITE);
          clear(40, (122 - m_JumpHeight) + 50, 32, 8, BLACK);
          m_IsDrawed = true;
        }
      }
    }

    else
    {
      for (int i=0; i<4; i++)
      {
        if (Frame::fourFrames == i)
        {
          draw(40, 122 - m_JumpHeight, 40, 64, charDown, i, BLACK, MAROON, RED, WHITE);
          clear(40, (122 - m_JumpHeight) - 8, 40, 8, BLACK);
          m_IsDrawed = true;
        }
      }
    }
  }
  
}

/*----------------------------------------//
                Player Dead
//----------------------------------------*/

void Player::dead(void)
{
  
}

/*----------------------------------------//
                Start Player
//----------------------------------------*/

void Player::start(void)
{

  if (SW::interrupt0 == ON)
  {
    if (m_IsReset == false)
    {
      clear(40, 140, 40, 40, BLACK);
      m_JumpTemp = 0;
      m_JumpHeight = 0;
      m_IsUp = true;
      m_IsJump = true;
      m_IsReset = true;
    }
  }

  if (m_IsJump == false)
  {
    running();
  }
  
  else
  {
    jumping();
  }

}