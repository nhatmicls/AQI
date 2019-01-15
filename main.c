#include <msp430.h> 


/**
 * main.c
 */



void clock_init()
{
    DCOCTL=CALDCO_1MHZ;
    BCSCTL1=CALBC1_1MHZ;
}

void time_init()
{
    TA0CTL = TASSEL_2 + ID_3 + MC_1 + TAIE;
    TA0CCR1=62500;
    TA0CCTL1=CCIE;
}

void LCD_init()
{

}

void PM25_init()
{

}

void MQ135_init()
{

}

void init()
{
    clock_init();
    time_init();
    LCD_init();
    PM25_init();
    MQ135_init();
    P1DIR = 0x00;
    P1OUT = 0x00;
}

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	init();
	P1DIR |= BIT0;
	P1OUT |= BIT0;
	_BIC_SR(CPUOFF+GIE);
	while (1)
	{
	    _no_operation();
	}
}

#pragma vector=TIMER0_A1_VECTOR
__interrupt void TimeA0()
{
    P1OUT ^= BIT0;
}
