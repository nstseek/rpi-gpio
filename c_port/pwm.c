/*
    This only works with the gpio 2 already exported and with the output mode set
    This is slower than RPi GPIO Python lib, it can't handle +100Hz frequencies very well

    EH O KARALHO PORRA OS GURI SAO BRABO BUCETA
*/

#include "c_gpio.h"
// #include "soft_pwm.h"

int main() {
    //  Esse setup aqui seta o mapa de gpio com os enderecos de memoria insanos la e deve fazer mais coisas
    setup();
    /*  Esse setup_gpio define o modo de cada pino
        
        O 1 argumento eh o numero de gpio que nesse caso é o 2, pino 3 da rpi b 3+

        O 2 argumento eh a direcao do pino, 0 pra out e 1 pra in

        O 3 argumento eh o pulldown resistor, se aplica so pra quando o pino eh in
    */
    setup_gpio(2, 0, 0);
    /*
        Esse output_gpio define um valor de output para um pino

        O 1 argumento eh o numero de gpio que nesse caso é o 2, pino 3 da rpi b 3+

        O 2 argumento eh o valor a ser enviado pra gpio escolhida, 1 pra high e 0 pra low
    */
    output_gpio(2, 1);
}