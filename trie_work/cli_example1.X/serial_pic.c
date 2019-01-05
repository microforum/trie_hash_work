/*
 * File:   serial_pic.c
 * Author: joejulicher
 *
 * Created on January 5, 2019, 1:51 PM
 */


#include <xc.h>

int serial_open(void)
{
    return 1;
}

size_t serial_write(char *data, size_t length)
{
    return length;
}
size_t serial_read(char *data, size_t length)
{
    const char *testdata = "$GNGSA,asdf\n$GPGSV,asdf\n$GLGSV,asdf\n$GPRMC,asdf\n$GPGGA,asdf\n";
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