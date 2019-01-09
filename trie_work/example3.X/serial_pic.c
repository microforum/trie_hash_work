/*
 * File:   serial_pic.c
 * Author: joejulicher
 *
 * Created on January 5, 2019, 1:51 PM
 */


#include <xc.h>
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)

int serial_open(void)
{
    TXSTAbits.TXEN = 1;
    TXSTAbits.SYNC = 0;
    RCSTAbits.SPEN = 1;
    while(!TRMT);
    return 1;
}

void putch(char c)
{
    TXREG = c;
}

size_t serial_write(char *data, size_t length)
{
    return length;
}
size_t serial_read(char *data, size_t length)
{
    const char testdata[] = "$GNGSA,asdf\n$GPGSV,asdf\n$GLGSV,asdf\n$GPRMC,asdf\n$GPGGA,asdf\n";
    static int index = 0;
    
    for(int x = 0; x < length;x++)
    {
        data[x] = testdata[index++];
        if(index > sizeof(testdata)-1)
        {
            index = 0;
        }
    }
    return length;
}

void serial_close(void)
{
    
}