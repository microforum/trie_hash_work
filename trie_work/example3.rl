
#include <string.h>
#include <stdio.h>
#include "serial_port.h"

%%  machine foo;
%%  write data;

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
    const char *p = word;
    const char *pe = word + strlen(word);
    int cs;
    enum wordTokens returnValue = NO_WORD;

%%{
action gpgga { returnValue = GPGGA; fbreak; }
action gngsa { returnValue = GNGSA; fbreak; }
action gpgsv { returnValue = GPGSV; fbreak; }
action gpbod { returnValue = GPBOD; fbreak; }
action gpdbt { returnValue = GPDBT; fbreak; }
action gpdcn { returnValue = GPDCN; fbreak; }

gpgga = ('GPGGA') @gpgga;
gngsa = ('GNGSA') @gngsa;
gpgsv = ('GPGSV') @gpgsv;
gpbod = ('GPBOD') @gpbod;
gpdbt = ('GPDBT') @gpdbt;
gpdcn = ('GPDCN') @gpdcn;

main := ( gpgga | gngsa | gpgsv | gpbod | gpdbt | gpdcn )*;

}%%
    %% write init;
    %% write exec noend;

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
