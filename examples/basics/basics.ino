#include <Arduino.h>
#include "IO22C04.h"
#include <TimerOne.h>

/*
 * In this basic example shows how to read inputs, switches,
 * activate relays and display on the seven segment display 
 * 
 * Each switch value is output to each Relay
 * terminal input values are displayed in serial monitor
 * A counter is displayed on the seven segment display.
 */
 
 //create controller object
IO22C04 controller;

int counter = 0;
unsigned long counter_timer = 0;

//callback function to update the seven segment display at high speed
//by a timer interrupt
void update_display()
{
  controller.display_update();
}

void setup()
{
  // put your setup code here, to run once:
  Timer1.initialize(6000);
  Timer1.attachInterrupt(update_display);
  Serial.begin(9600);
  
  controller.gpio_init();//initialize switches,relays,inputs and display pins
}

void loop()
{

  if (millis() - counter_timer >= 1000)
  {
    controller.set_value(counter);//set the counter value to display on the controller
    counter++;

    //serial out input status
    Serial.print("IN_1:");
    Serial.println(digitalRead(IN_1_PIN));
    Serial.print("IN_2:");
    Serial.println(digitalRead(IN_2_PIN));
    Serial.print("IN_3:");
    Serial.println(digitalRead(IN_3_PIN));
    Serial.print("IN_4:");
    Serial.println(digitalRead(IN_4_PIN));
    Serial.println();

    counter_timer = millis();
  }
  //switches activates relays
  int K1 = !digitalRead(SW1_PIN);
  digitalWrite(RELAY1_PIN, K1);

  int K2 = !digitalRead(SW2_PIN);
  digitalWrite(RELAY2_PIN, K2);

  int K3 = !digitalRead(SW3_PIN);
  digitalWrite(RELAY3_PIN, K3);

  int K4 = !digitalRead(SW4_PIN);
  digitalWrite(RELAY4_PIN, K4);
}
