#include <iostream>
// #include <chrono>
// #include <thread>
#include <wiringPi.h>

#define LEDPIN 2

using namespace std;

int main() {
  cout << "Starting PWM control..." << endl;
  wiringPiSetupGpio();
  cout << "GPIO ports set up." << endl;
  // pinMode(LEDPIN, PWM_OUTPUT);
  pinMode(LEDPIN, OUTPUT);
  cout << "Pin set up." << endl;
  bool high = true;
  while(true) {
    if (high) {
       high = false;
       cout << "Pin " << LEDPIN << " set to low." << endl;

     } else {
       high = true;
       cout << "Pin " << LEDPIN << " set to high." << endl;
     }
     digitalWrite(LEDPIN, high ? HIGH : LOW);
     delay(500);
   }
}
