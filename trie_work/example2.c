
#include <string.h>
#include <stdio.h>
#include "serial_port.h"

char * NMEA_getWord(void)
{
    static char buffer[7];
    
    memset(buffer,0,sizeof(buffer));
    do
    {
        serial_read(buffer,1);
    } while(buffer[0] != '$');
    for(int x=0;x<sizeof(buffer)-1;x++)
    {
        serial_read(&buffer[x], 1);
        if(buffer[x]==',')
        {
            buffer[x] = 0;
            break;
        }
    }
    return buffer;
}


// const char *wordList[] = {"GPGGA","GNGSA","GPGSV","GPBOD","GPDBT","GPDCN"};
enum wordTokens {NO_WORD = -1,GPGGA,GNGSA,GPGSV,GPBOD,GPDBT,GPDCN};

enum wordTokens NMEA_findToken(char *word)
{
    enum wordTokens returnValue = NO_WORD;
    char c = *word++;
    if(c == 'G')
    {
        c = *word++;
       if(c == 'P')
       {
           c = *word++;
           if(c == 'G') // gpGga or gpGsv
           {
               c = *word++;
               if(c == 'G') // gpgGa
               {
                   c = *word++;
                   if(c == 'A')
                   {
                       if(*word == 0) // found GPGGA
                       {
                           returnValue = GPGGA;
                       }
                   }
               }
               else if(c == 'S') // gpgSv
               {
                   c = *word++;
                   if(c == 'V')
                   {
                       if(*word == 0) // found GPGSV
                       {
                           returnValue = GPGSV;
                       }
                   }
               }
           }
           else if(c == 'B') // gpBod
           {
               c = *word++;
               if(c == 'O')
               {
                   c = *word++;
                   if(c == 'D')
                   {
                       if(*word == 0)
                       {
                           returnValue = GPBOD;
                       }
                   }
               }
           }
           else if(c == 'D') // gpDcn or gpDbt
           {
               c = *word++;
               if(c == 'C')
               {
                   c = *word++;
                   if(c == 'N')
                   {
                       if(*word == 0)
                       {
                           returnValue = GPDCN;
                       }
                   }
               }
               else if(c == 'B')
               {
                   c = *word++;
                   if(c == 'T')
                   {
                       if(*word == 0)
                       {
                           returnValue = GPDBT;
                       }
                   }
               }
           }
       }
       else if(c == 'N') // gNgsa
       {
           c = *word++;
           if(c == 'G')
           {
               c = *word++;
               if(c == 'S')
               {
                   c = *word++;
                   if(c == 'A')
                   {
                       if(*word == 0)
                       {
                           returnValue = GNGSA;
                       }
                   }
               }
           }
       }
    }
    return returnValue;
}

int main(int argc, char **argv)
{
  if(serial_open()>0)
  {
      for(int x = 0; x < 24; x ++)
      {
        char *w = NMEA_getWord();
        enum wordTokens t = NMEA_findToken(w);
          printf("word %s,",w);
          if(t >= 0)
              printf("token %d\n",t);
          else
              printf("no match\n");
      }
  }
  serial_close();
  return 0;
}
