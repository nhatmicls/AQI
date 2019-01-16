#include <msp430.h> 

/**
 * main.c
 */

int counter=0,timehms[3]={0,0,0};

void clock_init()
{
    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL = CALDCO_16MHZ;
}

void time_init()
{
    TACTL = TASSEL_2 + ID_3 + MC_1 + TAIE;
    TACCR0 = 40000;
    TACCTL0=CCIE;
}

void LCD_init()
{
    UCA0CTL0=UCCKPL+UCMSB+UCMST+UCSYNC;
    UCA0CTL1=UCSSEL_2;
}

void PM25_init()
{

}

void MQ135_init()
{

}

void init()
{
    time_init();
    clock_init();
    LCD_init();
    PM25_init();
    MQ135_init();
}

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    _BIS_SR(GIE);
    init();
    P1DIR |= BIT0;
    P1OUT |= BIT0;
    while (1);
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A_1()
{
    switch (TA0IV) {
        case 10:
            counter++;
            break;
        default:
            break;
    }
    if(counter==50)
    {
        P1OUT ^= BIT0;
        counter = 0;
        timehms[2]++;
        if (timehms[2]==60)
        {
            timehms[1]++;
            timehms[2]=0;
            if (timehms[1]==60)
            {
                timehms[1]=0;
                timehms[0]++;
            }
        }
    }
}
