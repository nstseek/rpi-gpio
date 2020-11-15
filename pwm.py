import RPi.GPIO as gpio;
import time;

gpio.setmode(gpio.BOARD);

ledPin = 3;

gpio.setup(ledPin, gpio.OUT);

ledPwm = gpio.PWM(ledPin, 25);

ledPwm.start(50);

time.sleep(3);

while True:
    inputVal = raw_input('Insert `f` to change frequency, `d` to change the duty cycle or `x` to exit.\n');
    if inputVal == 'x':
        gpio.cleanup();
        exit();
    elif inputVal == 'f':
        ledPwm.ChangeFrequency(int(raw_input('Insert the new frequency:\n')));
        print('Frequency set.');
    elif inputVal == 'd':
        ledPwm.ChangeDutyCycle(int(raw_input('Insert the new duty cycle:\n')));
        print('Duty cycle set.');
    else:
        print('Invalid option');

# while True:
#     gpio.output(ledPin, 1);
#     time.sleep(0.01);
#     gpio.output(ledPin, 0);
#     time.sleep(0.01);
    