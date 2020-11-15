/*
    This does not handle the clock very well, it lags when we have more than one thing running at the same time
*/

#include <unistd.h>
#include <sys/wait.h>
#include "c_gpio.h"
#include "soft_pwm.h"

#define ledPin 2

int main() {
    //  Esse setup aqui seta o mapa de gpio com os enderecos de memoria insanos la e deve fazer mais coisas
    setup();
    /*  Esse setup_gpio define o modo de cada pino
        
        O 1 argumento eh o numero de gpio que nesse caso é o 2, pino 3 da rpi b 3+

        O 2 argumento eh a direcao do pino, 0 pra out e 1 pra in

        O 3 argumento eh o pulldown resistor, se aplica so pra quando o pino eh in
    */
    setup_gpio(ledPin, 0, 0);
    /*
        Esse output_gpio define um valor de output para um pino

        O 1 argumento eh o numero de gpio que nesse caso é o 2, pino 3 da rpi b 3+

        O 2 argumento eh o valor a ser enviado pra gpio escolhida, 1 pra high e 0 pra low
    */
    // output_gpio(ledPin, 1);
    pwm_set_frequency(ledPin, 50);
    pwm_set_duty_cycle(ledPin, 25);
    pwm_start(ledPin);
    int status = 0;
    while(1) {
        sleep(1000);
    }
}