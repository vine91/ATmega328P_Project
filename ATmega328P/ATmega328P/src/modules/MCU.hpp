﻿/*
 *    NOTE        - MCU.hpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.05.30
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#pragma once
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#define OFF 0
#define ON 1
#define LOW 0
#define HIGH 1
#define IN 0
#define OUT 1

#define B 0
#define C 1
#define D 2
#define OC0A 3
#define OC0B 4
#define OC1A 5
#define OC1B 6
#define OC2A 7
#define OC2B 8

#define OVF 0
#define COMP 1
#define CORRECT 0
#define FAST 1
#define MAINTAIN 0
#define DOWN 1
#define UP 2

#define _OCR0A 0xFF   // Compare with 0xFF	Timer0
#define _OCR2A 0xA0   // Compare with 0xA0	Timer2
#define _OCR1AH 0x3D
#define _OCR1AL 0x09  // Compare with 0x3D09	Timer1


/*
//==========================================
              NAMESPACE - MCU
==========================================//
*/

namespace MCU
{

  uint8_t insertBit(uint8_t bitValue, bool isHigh);

  namespace Features
  {
    uint8_t hex(int8_t decimal);
    uint8_t ASKII(int8_t decimal);
  }

  namespace Setting
  {
    void beginPort(int8_t port, bool isOutput);
    void beginINT(int8_t INTIndex, int8_t INTMode);
    void beginPCINT(int8_t PCINTIndex);
    void beginTimer(int8_t timerIndex, bool timerMode);
    void beginPWM(int8_t PWMIndex, bool PWMMode);
    void beginSPI(void);
  }

}