#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;
    P1DIR |= (BIT0);    //Sets direction of P1 Bit 0 to Output
    P5DIR &= ~(BIT6);   //Sets direction of P5 Bit 6 to Input
    P5REN |= (BIT6);    //Enables the resistor for P5 Bit 6
    P5OUT |= (BIT6);    //Sets the ressistor for P5 Bit 6 to Pull Up

    while(1){
       int number = P5IN & BIT6;
       if(number == 0){
           P1OUT |= BIT0;
       }else{
           P1OUT &= ~BIT0;
       }

    }

    return 0;
}
