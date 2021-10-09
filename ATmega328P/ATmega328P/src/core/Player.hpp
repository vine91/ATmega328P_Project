/*
 *    NOTE        - Player.hpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.20
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#pragma once
#include "../modules/MCU.hpp"
#include "../modules/SW.hpp"
#include "../modules/TFT.hpp"
#include "../assets/CharRun.hpp"
#include "../assets/CharUp.hpp"
#include "../assets/CharDown.hpp"

#include "Frame.hpp"


/*
//==========================================
              CLASS - Player
==========================================//
*/

class Player : private TFT
{

private:
  int8_t m_JumpSpeed;
  int8_t m_JumpTemp;
  int8_t m_JumpHeight;
  bool m_IsReset;
  bool m_IsUp;
  bool m_IsDrawed;

  void running(void);
  void jumping(void);

public:
  Player() : TFT() { m_IsReset = false; m_IsJump = false; m_IsUp = false; }
  ~Player(){};

  void start(void);
  void dead(void);
  bool m_IsJump;
  
};