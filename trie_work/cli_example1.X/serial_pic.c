/*
 * File:   serial_pic.c
 * Author: joejulicher
 *
 * Created on January 5, 2019, 1:51 PM
 */


#include "../serial_port.h"
#include <xc.h>

int serial_open(void)
{
    TXSTAbits.TXEN = 1;
    TXSTAbits.SYNC = 0;
    RCSTAbits.SPEN = 1;
    RCSTAbits.CREN = 1;
    while(!TRMT);
    return 1;
}

void putch(char c)
{
    TXREG = c;
}

ssize_t serial_write(char *data, ssize_t length)
{
    return length;
}


ssize_t serial_read(char *data, ssize_t length)
{
    while(length--)
    {
        while(PIR1bits.RCIF==0);
            *data++ = RCREG;
    }
    return length;
}

void serial_close(void)
{
    
}