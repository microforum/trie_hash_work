
/* #line 1 "example3.rl" */

// compile into C with ragel
// ragel -C -L example3.rl -o example3.c
//

#include <string.h>
#include <stdio.h>
#include "serial_port.h"

#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)

#include <xc.h>
void putch(char c)
{
    TXREG = c;
}

/* #line 11 "example3.rl" */

/* #line 16 "example3.c" */
static const char _foo_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 1, 6, 1, 
	7
};

static const char _foo_key_offsets[] = {
	0, 0, 2, 3, 4, 5, 9, 11, 
	12, 13, 15, 16, 17, 19, 20, 21, 
	22, 23
};

static const char _foo_trans_keys[] = {
	78, 80, 71, 83, 65, 66, 68, 71, 
	82, 79, 87, 68, 67, 66, 67, 84, 
	78, 71, 83, 65, 86, 77, 67, 71, 
	0
};

static const char _foo_single_lengths[] = {
	0, 2, 1, 1, 1, 4, 2, 1, 
	1, 2, 1, 1, 2, 1, 1, 1, 
	1, 1
};

static const char _foo_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0
};

static const char _foo_index_offsets[] = {
	0, 0, 3, 5, 7, 9, 14, 17, 
	19, 21, 24, 26, 28, 31, 33, 35, 
	37, 39
};

static const char _foo_trans_targs[] = {
	2, 5, 0, 3, 0, 4, 0, 17, 
	0, 6, 9, 12, 15, 0, 7, 8, 
	0, 17, 0, 17, 0, 10, 11, 0, 
	17, 0, 17, 0, 13, 14, 0, 17, 
	0, 17, 0, 16, 0, 17, 0, 1, 
	0, 0
};

static const char _foo_trans_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 7, 0, 13, 0, 0, 0, 0, 
	9, 0, 11, 0, 0, 0, 0, 1, 
	0, 5, 0, 0, 0, 15, 0, 0, 
	0, 0
};

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

    
/* #line 117 "example3.c" */
	{
	cs = foo_start;
	}

/* #line 68 "example3.rl" */
    
/* #line 124 "example3.c" */
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _foo_trans_keys + _foo_key_offsets[cs];
	_trans = _foo_index_offsets[cs];

	_klen = _foo_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _foo_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	cs = _foo_trans_targs[_trans];

	if ( _foo_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _foo_actions + _foo_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
/* #line 46 "example3.rl" */
	{ returnValue = GPGGA; {p++; goto _out; } }
	break;
	case 1:
/* #line 47 "example3.rl" */
	{ returnValue = GNGSA; {p++; goto _out; } }
	break;
	case 2:
/* #line 48 "example3.rl" */
	{ returnValue = GPGSV; {p++; goto _out; } }
	break;
	case 3:
/* #line 49 "example3.rl" */
	{ returnValue = GPBOD; {p++; goto _out; } }
	break;
	case 4:
/* #line 50 "example3.rl" */
	{ returnValue = GPDBT; {p++; goto _out; } }
	break;
	case 5:
/* #line 51 "example3.rl" */
	{ returnValue = GPDCN; {p++; goto _out; } }
	break;
	case 6:
/* #line 52 "example3.rl" */
	{ returnValue = GPBWC; {p++; goto _out; } }
	break;
	case 7:
/* #line 53 "example3.rl" */
	{ returnValue = GPRMC; {p++; goto _out; } }
	break;
/* #line 227 "example3.c" */
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	p += 1;
	goto _resume;
	_out: {}
	}

/* #line 69 "example3.rl" */

    return returnValue;
}

int main(int argc, char **argv)
{
    TXSTAbits.TXEN = 1;
    TXSTAbits.SYNC = 0;
    RCSTAbits.SPEN = 1;
    while(!TRMT);

    printf("Starting Up\nReady\n");
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
