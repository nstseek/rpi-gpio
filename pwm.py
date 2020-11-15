import RPi.GPIO as gpio;
import time;

gpio.setmode(gpio.BOARD);

ledPin = 3;
# esse pino na funcao setup_gpio em c deve sempre ser o numero da porta gpio e nao do pino, por exemplo, pra configurar o pino 3 do rpi b 3+
# tu vai colocar 2 nesse valor aqui e passar 2 como parametero de gpio pra funcao, porque o pino 3 eh o pino da gpio2 da placa

gpio.setup(ledPin, gpio.OUT);
# na funcao setup_gpio do c, o valor do in/out vulgo parametro direction da funcao eh 0 pra out e 1 pra in

# gpio.output(ledPin, 0);

ledPwm = gpio.PWM(ledPin, 50);

ledPwm.start(1);

while True:
    continue;

# time.sleep(3);

# while True:
#     inputVal = raw_input('Insert `f` to change frequency, `d` to change the duty cycle or `x` to exit.\n');
#     if inputVal == 'x':
#         gpio.cleanup();
#         exit();
#     elif inputVal == 'f':
#         ledPwm.ChangeFrequency(int(raw_input('Insert the new frequency:\n')));
#         print('Frequency set.');
#     elif inputVal == 'd':
#         ledPwm.ChangeDutyCycle(int(raw_input('Insert the new duty cycle:\n')));
#         print('Duty cycle set.');
#     else:
#         print('Invalid option');

# while True:
#     gpio.output(ledPin, 1);
#     time.sleep(0.01);
#     gpio.output(ledPin, 0);
#     time.sleep(0.01);
    