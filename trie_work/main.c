//
//  main.c
//  trie_work
//
//  Created by Joe Julicher on 12/19/18.
//  Copyright © 2018 Joe Julicher. All rights reserved.
//

#include <stdio.h>
//#include "trie_builder.h"
#include "trie_search.h"
#include "serial_port.h"
#include <string.h>
#include <ctype.h>
#include "nmea.h"

// Driver
int main()
{
    const char *output[] = {"Not present in trie", "Present in trie"};
    nmea_init();

    // Search for different keys
    printf("%s --- %d\n", "GPWPL", trie_search( "GPWPL",5) );
    printf("%s --- %d\n", "these", trie_search( "these",5) );
    printf("%s --- %d\n", "GPAPA", trie_search( "GPAPA",5) );
    printf("%s --- %d\n", "GPWNC", trie_search( "GPWNC",5) );

    if(serial_open("/dev/cu.BadElfGPS013356-Bluetoo",9600)>0)
    {
        while(1)
        {
            char buffer[256];
            char lineBuffer[256];
            ssize_t l = 0;
            ssize_t rxSize = 0;
            int parseMode = 0;

            memset(buffer,0,sizeof(buffer));
            rxSize = serial_read(buffer,sizeof(buffer)-1);
            
            if(rxSize < 0)
            {
                perror("serial read error ");
            }
            else if(rxSize == 0)
            {
                perror("end of file");
            }
            else
            {
                for(unsigned int x=0;x<rxSize;x++)
                {
                    char c = buffer[x];
                    switch(parseMode)
                    {
                        default:
                        case 0: // look for the '$' to indicate the start of a NMEA frame
                            if(c == '$')
                            {
                                parseMode = 1;
                                l = 0;
                                //lineBuffer[l++] = '$';
                            }
                            break;
                        case 1: // collect the line
                            if(c == 13)
                            {
                                c = 0;
                                parseMode = 0;
                                process_a_line(lineBuffer,l);
                                l = 0;
                                memset(lineBuffer,0,sizeof(lineBuffer));
                            }
                            else
                            {
                                lineBuffer[l++] = c;
                            }
                            break;
                    }
                }
            }
            usleep(100); // save some battery life in this loop.
        }
    }
    return 0;
}
