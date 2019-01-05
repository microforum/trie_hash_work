
#include <string.h>
#include <stdio.h>
#include "serial_port.h"

#include <xc.h>
void putch(char c)
{
    RCSTAbits.SPEN = 1;
    TXSTAbits.TXEN = 1;
    TXSTAbits.SYNC = 0;
    TXREG = c;
    NOP();
}

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

const char *wordList[] = {"GPGGA","GNGSA","GPGSV","GPBOD","GPDBT","GPDCN"};
enum wordTokens {NO_WORD = -1,GPGGA,GNGSA,GPGSV,GPBOD,GPDBT,GPDCN};

enum wordTokens NMEA_findToken(char *word)
{
  enum wordTokens retValue = NO_WORD;
  for(int x=0; x < sizeof(wordList)/sizeof(*wordList);x++)
  {
    if(strcmp(word,wordList[x])==0)
    {
      retValue = x;
      break;
    }
  }
  return retValue;
}

int main(int argc, char **argv)
{
    printf("Starting Up\n");
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
