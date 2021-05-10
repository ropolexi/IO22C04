# 4 Channel Pro mini PLC Board (IO22C04)
This arduino library is for IO22C04 board with either

- ATmega32u4 (pro micro)
- ATmega328 (pro mini)

## Dependencies

TimerOne Library

https://github.com/PaulStoffregen/TimerOne


## Relay outputs
```
#define RELAY1_PIN 10
#define RELAY4_PIN 6
#if defined(__AVR_ATmega32U4__)
#define RELAY2_PIN 16
#define RELAY3_PIN 14
#elif defined(__AVR_ATmega328P__)
#define RELAY2_PIN 11
#define RELAY3_PIN 12
#endif
```

## Input Terminals
```
#define IN_1_PIN A1
#define IN_2_PIN A0
#define IN_3_PIN A3
#define IN_4_PIN A2
```

## Switches
```
#define SW1_PIN 2
#define SW2_PIN 3
#define SW3_PIN 4
#define SW4_PIN 5
```

## seven segment display pins
```
#define LATCH_PIN 8
#define CLOCK_PIN 9
#define DATA_PIN 7
```