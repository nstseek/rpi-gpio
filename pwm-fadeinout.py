import RPi.GPIO as gpio;
import time;

gpio.setmode(gpio.BOARD);

ledPin = 3;

gpio.setup(ledPin, gpio.OUT);

ledPwm = gpio.PWM(ledPin, 500);

dutyCycle = 0;

reverse = False;

ledPwm.start(dutyCycle);

while True:
        
    if dutyCycle == 100:
        reverse = True;    
    if dutyCycle == 0:
        reverse = False;

    increment = 0;

    if reverse == True:
        increment = -1;
    else:
        increment = 1;
    
    dutyCycle = dutyCycle + increment;
    ledPwm.ChangeDutyCycle(dutyCycle);
    time.sleep(0.01);
