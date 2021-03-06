/*
 *    NOTE        - TFT.hpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.17
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#pragma once
#include "MCU.hpp"

/*------------------------------------------*/
#define BLACK 0x0000        //   0.  0.  0  //
#define WHITE 0xFFFF        //  31. 63. 31  //

#define DARKGRAY 0x39E7     //   7. 15.  7  //
#define GRAY 0x7BEF         //  15. 31. 15  //
/*------------------------------------------*/
#define BROWN 0x3800        //   7.  0.  0  //
#define MAROON 0x7800       //  15.  0.  0  //
#define RED 0xF800          //  31.  0.  0  //

#define DARKGREEN 0x01E0    //   0. 15.  0  //
#define MEDIUMGREEN 0x03E0  //   0. 31.  0  //
#define GREEN 0x07E0        //   0. 63.  0  //

#define DARKBLUE 0x0007     //   0.  0.  7  //
#define MEDIUMBLUE 0x000F   //   0.  0. 15  //
#define BLUE 0x001F         //   0.  0. 31  //
/*------------------------------------------*/
#define OLIVE 0x39E0        //   7. 15.  0  //
#define OCHER 0x7BE0        //  15. 31.  0  //
#define YELLOW 0xFFE0       //  31. 63.  0  //

#define DARKCYAN 0x01E7     //   0. 15.  7  //
#define TURQUOISE 0x03EF    //   0. 31. 15  //
#define CYAN 0x07FF         //   0. 63. 31  //

#define PURPLE 0x3807       //   7.  0.  7  //
#define ORCHID 0x780F       //  15.  0. 15  //
#define PINK 0xF81F         //  31.  0. 31  //
/*------------------------------------------*/


#define _SPEED
#ifdef _SPEED

#define CS 0
#define RST 1
#define RS 2
#define MOSI 3
#define SCK 5

#define CS_HIGH (PORTB |= (1 << CS))
#define CS_LOW (PORTB &= ~(1 << CS))
#define RST_HIGH (PORTB |= (1 << RST))
#define RST_LOW (PORTB &= ~(1 << RST))
#define RS_HIGH (PORTB |= (1 << RS))
#define RS_LOW (PORTB &= ~(1 << RS))

/*
//==========================================
                CLASS - SPI
==========================================//
*/

class SPI
{

public:
  SPI(){};
  ~SPI(){};

  void sendBit(uint8_t bitValue);
  void exportCommand(uint8_t commandValue);
  void exportData(uint8_t dataValue);
  void exportLongData(uint16_t longDataValue);

};

/*
//==========================================
                CLASS - TFT
==========================================//
*/

class TFT : protected SPI
{

private:
  int16_t m_Width;
  int16_t m_Height;

public:
  TFT() : SPI() { m_Width = 240; m_Height = 320; }
  TFT(int16_t TFTWidth, int16_t TFTHeight) : SPI() { m_Width = TFTWidth; m_Height = TFTHeight; }
  ~TFT(){};

  void begin(void);
  void setRotation(int8_t mode);
  void setAddress(int16_t xPos, int16_t yPos, int16_t width, int16_t height);
  void fillScreen(uint16_t colorValue);
  void fillPixel(int16_t xPos, int16_t yPos, uint16_t colorValue);
  void clear(int16_t xPos, int16_t yPos, int16_t width, int16_t height, uint16_t colorValue);

  void draw(int16_t xPos, int16_t yPos, int16_t width, int16_t height, const uint8_t *bitmap,
    uint16_t color0, uint16_t color1);

  void draw(int16_t xPos, int16_t yPos, int16_t width, int16_t height, const uint8_t *bitmap,
    uint16_t color0, uint16_t color1, uint16_t color2, uint16_t color3);

  void draw(int16_t xPos, int16_t yPos, int16_t width, int16_t height, const unsigned char (*bitmap)[100], int8_t tileSelection,
    uint16_t color0, uint16_t color1, uint16_t color2, uint16_t color3);

  void draw(int16_t xPos, int16_t yPos, int16_t width, int16_t height, const unsigned char (*bitmap)[120], int8_t tileSelection,
    uint16_t color0, uint16_t color1, uint16_t color2, uint16_t color3);

};

#endif


#ifdef _SCALE

// Only for scalability, Slow speed. //

class SPI
{

private:
  int8_t m_CS;
  int8_t m_RST;
  int8_t m_RS;
  int8_t m_MOSI;
  int8_t m_SCK;

public:
  SPI(int8_t CS, int8_t RST, int8_t RS, int8_t MOSI, int8_t SCK)
  {
    m_CS = CS;
    m_RST = RST;
    m_RS = RS;
    m_MOSI = MOSI;
    m_SCK = SCK;
  }
  ~SPI(){};

  inline void CS_HIGH(void) { PORTB |= (1 << m_CS); }
  inline void CS_LOW(void) { PORTB &= ~(1 << m_CS); }
  inline void RST_HIGH(void) { PORTB |= (1 << m_RST); }
  inline void RST_LOW(void) { PORTB &= ~(1 << m_RST); }
  inline void RS_HIGH(void) { PORTB |= (1 << m_RS); }
  inline void RS_LOW(void) { PORTB &= ~(1 << m_RS); }

  void sendBit(uint8_t bitValue);
  void exportCommand(uint8_t commandValue);
  void exportData(uint8_t dataValue);
  void exportLongData(uint16_t longDataValue);

};

class TFT : public SPI
{

private:
  int16_t m_Width;
  int16_t m_Height;
  int16_t m_Temp;

public:
  TFT(int8_t CS, int8_t RST, int8_t RS, int8_t MOSI, int8_t SCK)
    : SPI(CS, RST, RS, MOSI, SCK){};
  ~TFT(){};

  void begin(int16_t TFTWidth, int16_t TFTHeight);
  void setRotation(uint8_t rotation);
  void setAddress(int16_t xPos, int16_t yPos, int16_t width, int16_t height);
  void fillScreen(uint16_t colorValue);
  void draw(int16_t xPos, int16_t yPos, int16_t width, int16_t height, const uint8_t *bitmap, uint16_t color0Bit, uint16_t color1Bit);

};

#endif