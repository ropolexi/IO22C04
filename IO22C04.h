#ifndef IO22C04_H
#define IO22C04_H
#include <Arduino.h>

//Relay outputs
#define RELAY1_PIN 10
#define RELAY4_PIN 6
#if defined(__AVR_ATmega32U4__)
#define RELAY2_PIN 16
#define RELAY3_PIN 14
#elif defined(__AVR_ATmega328P__)
#define RELAY2_PIN 11
#define RELAY3_PIN 12
#endif

//Input Terminals
#define IN_1_PIN A1
#define IN_2_PIN A0
#define IN_3_PIN A3
#define IN_4_PIN A2

//Switches
#define SW1_PIN 2
#define SW2_PIN 3
#define SW3_PIN 4
#define SW4_PIN 5

//seven segment display pins
#define LATCH_PIN 8
#define CLOCK_PIN 9
#define DATA_PIN 7

class IO22C04
{

private:
  unsigned char SSD_SEG[30] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa7, 0xa1, 0x86, 0x8e, 0x89, 0x8b, 0xc7, 0xab, 0xc8, 0xa3, 0x8c, 0xaf, 0x87, 0xc1, 0xbf, 0xff}; //Common anode Digital Tube Character Gallery
  unsigned char SSD_NUM[4] = {1, 2, 4, 8};                                                                                                                                           //Tuble bit number
  unsigned char dat_buf[8];
  unsigned char dat;
  unsigned char com_num;
  int display_value;
  void displayOneBit();

public:
  IO22C04();
  void gpio_init();
  void update();
  void set_value(int value);
  
};
#endif