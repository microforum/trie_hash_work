
/* #line 1 "example3.rl" */

// compile into C with ragel
// ragel -C -L example3.rl -o example3.c
//

#include <string.h>
#include <stdio.h>
#include "serial_port.h"


/* #line 11 "example3.rl" */

/* #line 16 "example3.X/example3.c" */
static const int foo_start = 17;
static const int foo_first_final = 17;
static const int foo_error = 0;

static const int foo_en_main = 17;


/* #line 12 "example3.rl" */

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
enum wordTokens {NO_WORD = -1,GPGGA,GNGSA,GPGSV,GPBOD,GPDBT,GPDCN, GPRMC, GPBWC};

enum wordTokens NMEA_findToken(char *word)
{
    const char *p = word;
    const char *pe = word + strlen(word);
    int cs;
    enum wordTokens returnValue = NO_WORD;


/* #line 66 "example3.rl" */

    
/* #line 62 "example3.X/example3.c" */
	{
	cs = foo_start;
	}

/* #line 68 "example3.rl" */
    
/* #line 69 "example3.X/example3.c" */
	{
	switch ( cs )
	{
tr5:
/* #line 47 "example3.rl" */
	{ returnValue = GNGSA; {p++; cs = 17; goto _out;} }
	goto st17;
tr12:
/* #line 49 "example3.rl" */
	{ returnValue = GPBOD; {p++; cs = 17; goto _out;} }
	goto st17;
tr13:
/* #line 52 "example3.rl" */
	{ returnValue = GPBWC; {p++; cs = 17; goto _out;} }
	goto st17;
tr16:
/* #line 50 "example3.rl" */
	{ returnValue = GPDBT; {p++; cs = 17; goto _out;} }
	goto st17;
tr17:
/* #line 51 "example3.rl" */
	{ returnValue = GPDCN; {p++; cs = 17; goto _out;} }
	goto st17;
tr20:
/* #line 46 "example3.rl" */
	{ returnValue = GPGGA; {p++; cs = 17; goto _out;} }
	goto st17;
tr21:
/* #line 48 "example3.rl" */
	{ returnValue = GPGSV; {p++; cs = 17; goto _out;} }
	goto st17;
tr23:
/* #line 53 "example3.rl" */
	{ returnValue = GPRMC; {p++; cs = 17; goto _out;} }
	goto st17;
st17:
	p += 1;
case 17:
/* #line 108 "example3.X/example3.c" */
	if ( (*p) == 71 )
		goto st1;
	goto st0;
st0:
cs = 0;
	goto _out;
st1:
	p += 1;
case 1:
	switch( (*p) ) {
		case 78: goto st2;
		case 80: goto st5;
	}
	goto st0;
st2:
	p += 1;
case 2:
	if ( (*p) == 71 )
		goto st3;
	goto st0;
st3:
	p += 1;
case 3:
	if ( (*p) == 83 )
		goto st4;
	goto st0;
st4:
	p += 1;
case 4:
	if ( (*p) == 65 )
		goto tr5;
	goto st0;
st5:
	p += 1;
case 5:
	switch( (*p) ) {
		case 66: goto st6;
		case 68: goto st9;
		case 71: goto st12;
		case 82: goto st15;
	}
	goto st0;
st6:
	p += 1;
case 6:
	switch( (*p) ) {
		case 79: goto st7;
		case 87: goto st8;
	}
	goto st0;
st7:
	p += 1;
case 7:
	if ( (*p) == 68 )
		goto tr12;
	goto st0;
st8:
	p += 1;
case 8:
	if ( (*p) == 67 )
		goto tr13;
	goto st0;
st9:
	p += 1;
case 9:
	switch( (*p) ) {
		case 66: goto st10;
		case 67: goto st11;
	}
	goto st0;
st10:
	p += 1;
case 10:
	if ( (*p) == 84 )
		goto tr16;
	goto st0;
st11:
	p += 1;
case 11:
	if ( (*p) == 78 )
		goto tr17;
	goto st0;
st12:
	p += 1;
case 12:
	switch( (*p) ) {
		case 71: goto st13;
		case 83: goto st14;
	}
	goto st0;
st13:
	p += 1;
case 13:
	if ( (*p) == 65 )
		goto tr20;
	goto st0;
st14:
	p += 1;
case 14:
	if ( (*p) == 86 )
		goto tr21;
	goto st0;
st15:
	p += 1;
case 15:
	if ( (*p) == 77 )
		goto st16;
	goto st0;
st16:
	p += 1;
case 16:
	if ( (*p) == 67 )
		goto tr23;
	goto st0;
	}

	_out: {}
	}

/* #line 69 "example3.rl" */

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
  while(1);
  return 0;
}
