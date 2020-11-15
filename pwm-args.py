import RPi.GPIO as gpio;
import sys;

gpio.setmode(gpio.BOARD);

ledPin = 3;

gpio.setup(ledPin, gpio.OUT);

ledPwm = gpio.PWM(ledPin, int(sys.argv[1]));

ledPwm.start(int(sys.argv[2]));

while True:
    continue;
