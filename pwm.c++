#include <iostream>
// #include <chrono>
// #include <thread>
#include <wiringPi.h>

#define LEDPIN 3

using namespace std;

int main() {
  wiringPiSetup();
  // pinMode(LEDPIN, PWM_OUTPUT);
  pinMode(LEDPIN, OUTPUT);
  bool high = true;
  while(true) {
    if (high) {
      high = false;
    } else {
      high = true;
    }
    digitalWrite(LEDPIN, high ? HIGH : LOW);
    delay(500);
  }
}