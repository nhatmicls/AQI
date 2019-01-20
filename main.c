#include <msp430.h> 
#include "typedef.h"
#include "init_display.h"
#include "lib_math.h"
#include "lib_lcd.h"
#include "delay.h"
#include "const_data.h"
#include <stdlib.h>

#define C_BORDER    0x0005
#define s_num       110

void clean_area(uint);
void init_star(uchar);
void get_star_pos(uchar);

char index1[5],index2[5],index3[5];
int inputde[3]={0,0,0};
int cache1=0;

uchar space_char=1;     // space between chars
struct point3d_schar dots3d[s_num];

// help vars
uint x3=0;
sint x=0,y=0,x1=0,y1=0,x2=0,y2=0,r=0,i=0,z=0;
/**
 * main.c
 */

int counter=0,timehms[3]={0,0,0};
uchar cache[5];

void itoa(long unsigned int value, char* result, int base)
{
      // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0';}
    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do
    {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );
    // Apply negative sign
    if (tmp_value < 0)
        *ptr++ = '-';
    *ptr-- = '\0';
    while(ptr1 < ptr)
    {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
}

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

void ADC_init()
{
    ADC10CTL0=SREF_0+ADC10SHT_1+MSC+ADC10ON+ADC10IE;
    ADC10CTL1=INCH_2+ADC10DIV_4+ADC10SSEL_3+CONSEQ_0;
    ADC10AE0|=BIT1+BIT2;
    ADC10DTC1=0x2;
}

void PM25_init()
{
    P2DIR |= BIT0;
    P2OUT |= BIT0;
}

void MQ135_init()
{
    P2DIR &= ~BIT1;
}

void init()
{
    time_init();
    clock_init();
    LCD_init();
    ADC_init();
    PM25_init();
    MQ135_init();
}

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    _BIS_SR(GIE);
    init();
    init_USCI();                // init. USCI (SPI)
    init_LCD(C_BLACK);          // init. Display
    refe();
    while(1)
    {
        _no_operation();
    }
}

void refe()
{
    P2OUT &= ~BIT0;
    //wait_us(1);
    ADC10CTL0&=~ENC;
    ADC10SA=(int)inputde;
    ADC10CTL0|=ENC+ADC10SC;
    P2OUT |= BIT0;
    fill_display(240, 320, C_BLACK);
    draw_string(2, 2, string_00, C_RED, TRANSP, 1, 1);
    draw_string(2, 15, string_01, C_RED, TRANSP, 1, 1);
    draw_string(2, 28, string_02, C_RED, TRANSP, 1, 1);
    itoa(timehms[2],index1,10);
    itoa(inputde[1],index2,10);
    itoa(inputde[0],index3,10);
    draw_string(40, 2, index1, C_RED, TRANSP, 1, 1);
    draw_string(40, 15, index2, C_RED, TRANSP, 1, 1);
    draw_string(40, 28, index3, C_RED, TRANSP, 1, 1);
    if(inputde[0]>250)
        draw_string(2, 50, string_03, C_RED, TRANSP, 3, 3);
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
        counter = 0;
        timehms[2]++;
        if (timehms[2]==60)
        {
            timehms[1]++;
            timehms[2]=0;
            refe();
            if (timehms[1]==60)
            {
                timehms[1]=0;
                timehms[0]++;
            }
        }
            refe();
    }
}

void get_star_pos(uchar pos)
{
    x=dots3d[pos].x*100/dots3d[pos].z+120;
    y=dots3d[pos].y*100/dots3d[pos].z+160;
}

void init_star(uchar pos)
{
    dots3d[pos].x=get_rand(-80,80);
    dots3d[pos].y=get_rand(-80,80);
    dots3d[pos].z=get_rand(20,127);
}

void clean_area(uint color)
{
    x=46;
    while(x++<274)
        fill_rect(0,239,x,x,color);
}
