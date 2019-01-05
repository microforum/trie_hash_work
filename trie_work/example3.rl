

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
    %%{
    	machine NMEA;
    	access fsm->;

      action gpgga { returnValue = GPGGA; }
      action gngsa { returnValue = GNGSA; }
      action gpgsv { returnValue = GPGSV; }
      action gpbod { returnValue = GPBOD; }
      action gpdbt { returnValue = GPDBT; }
      action gpdcn { returnValue = GPDCN; }

      gpgga = ('GPGGA') @gpgga;
      
    	help = ( '-h' | '-H' | '-?' | '--help' ) 0 @help;
    	version = ( '-v' | '--version' ) 0 @version;
    	output = '-o' 0? string 0 @output;
    	spec = '-S' 0? string 0 @spec;
    	mach = '-M' 0? string 0 @mach;

    	main := (
    		help |
    		version |
    		output |
    		spec |
    		mach
    	)*;
    }%%
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
