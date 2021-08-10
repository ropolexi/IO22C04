#include "IO22C04.h"

IO22C04::IO22C04()
{
}

void IO22C04::gpio_init()
{
    pinMode(DATA_PIN, OUTPUT);
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
    pinMode(RELAY1_PIN, OUTPUT);
    pinMode(RELAY2_PIN, OUTPUT);
    pinMode(RELAY3_PIN, OUTPUT);
    pinMode(RELAY4_PIN, OUTPUT);

    pinMode(IN_1_PIN, INPUT_PULLUP);
    pinMode(IN_2_PIN, INPUT_PULLUP);
    pinMode(IN_3_PIN, INPUT_PULLUP);
    pinMode(IN_4_PIN, INPUT_PULLUP);

    pinMode(SW1_PIN, INPUT_PULLUP);
    pinMode(SW2_PIN, INPUT_PULLUP);
    pinMode(SW3_PIN, INPUT_PULLUP);
    pinMode(SW4_PIN, INPUT_PULLUP);
}
void IO22C04::displayOneBit()
{
    unsigned char ssd_dat;
    unsigned char bit_num;
    ssd_dat = SSD_SEG[dat];
    bit_num = SSD_NUM[com_num];
    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, bit_num);
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ssd_dat);
    digitalWrite(LATCH_PIN, HIGH);
}

void IO22C04::display_update()
{
    if (com_num < 3)
    {
        com_num++;
    }
    else
    {
        if (display_value_pre != display_value)
        {
            int temp_val = display_value;

            display_value_pre = display_value;
            dat_buf[0] = temp_val / 1000;
            temp_val = temp_val % 1000;
            dat_buf[1] = temp_val / 100;
            temp_val = temp_val % 100;
            dat_buf[2] = temp_val / 10;
            dat_buf[3] = temp_val % 10;
        }

        com_num = 0;
    }
    dat = dat_buf[com_num];
    displayOneBit();
}

void IO22C04::set_value(int value)
{
    display_value = value;
}
