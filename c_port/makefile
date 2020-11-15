 
all: pwm
 
pwm: pwm.o c_gpio.o soft_pwm.o
	gcc -o pwm pwm.o c_gpio.o soft_pwm.o -lpthread

pwm.o: pwm.c c_gpio.h soft_pwm.h
	gcc -o pwm.o pwm.c -c -lpthread

soft_pwm.o: soft_pwm.c soft_pwm.h c_gpio.h 
	gcc -o soft_pwm.o soft_pwm.c -c -lpthread
 
c_gpio.o: c_gpio.c c_gpio.h
	gcc -o c_gpio.o c_gpio.c -c -lpthread
 
clear:
	rm -rf *.o *~ pwm