/*
    This only works with the gpio 2 already exported and with the output mode set
    This is slower than RPi GPIO Python lib, it can't handle +100Hz frequencies very well
*/

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

#define TIME_UNIT 1000 // miliseconds

using namespace std;

fstream fs;

void value_gpio_high()
{    
    fs.open("/sys/class/gpio/gpio2/value", std::fstream::out);
    fs << '1';
    fs.close();
}

void value_gpio_low()
{
    fs.open("/sys/class/gpio/gpio2/value", std::fstream::out);
    fs << '0';
    fs.close();
}

int main() {
    const int frequency = 100;
    const int dutyCycle = 1;
    const int periodTime = TIME_UNIT / frequency;
    const int highMs = periodTime * (dutyCycle / 100.0);
    const int lowMs = periodTime - highMs;
    const struct timespec tsHigh = {
        0,
        highMs * 1000000
    };

    const struct timespec tsLow = {
        0,
        lowMs * 1000000
    };
    while(true) {
        value_gpio_high();
        nanosleep(&tsHigh, NULL);
        value_gpio_low();
        nanosleep(&tsLow, NULL);
    }
}