#include <Arduino.h>
#include "IO22C04.h"
#include <TimerOne.h>

IO22C04 display;

int counter = 0;
unsigned long counter_timer = 0;

void update_display()
{
  display.update();
}

void setup()
{
  // put your setup code here, to run once:
  Timer1.initialize(6000);
  Timer1.attachInterrupt(update_display);
  display.gpio_init();
}

void loop()
{

  if (millis() - counter_timer >= 1000)
  {
    display.set_value(counter);
    counter++;

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

  int K1 = !digitalRead(SW1_PIN);
  digitalWrite(RELAY1_PIN, K1);

  int K2 = !digitalRead(SW2_PIN);
  digitalWrite(RELAY2_PIN, K2);

  int K3 = !digitalRead(SW3_PIN);
  digitalWrite(RELAY3_PIN, K3);

  int K4 = !digitalRead(SW4_PIN);
  digitalWrite(RELAY4_PIN, K4);
}