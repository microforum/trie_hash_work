
/* #line 1 "example3.rl" */

#include <string.h>
#include <stdio.h>
#include "serial_port.h"


/* #line 7 "example3.rl" */

/* #line 12 "example3.c" */
static const char _foo_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5
};

static const char _foo_key_offsets[] = {
	0, 0, 2, 3, 4, 5, 8, 9, 
	10, 12, 13, 14, 16, 17, 18
};

static const char _foo_trans_keys[] = {
	78, 80, 71, 83, 65, 66, 68, 71, 
	79, 68, 66, 67, 84, 78, 71, 83, 
	65, 86, 71, 0
};

static const char _foo_single_lengths[] = {
	0, 2, 1, 1, 1, 3, 1, 1, 
	2, 1, 1, 2, 1, 1, 1
};

static const char _foo_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0
};

static const char _foo_index_offsets[] = {
	0, 0, 3, 5, 7, 9, 13, 15, 
	17, 20, 22, 24, 27, 29, 31
};

static const char _foo_trans_targs[] = {
	2, 5, 0, 3, 0, 4, 0, 14, 
	0, 6, 8, 11, 0, 7, 0, 14, 
	0, 9, 10, 0, 14, 0, 14, 0, 
	12, 13, 0, 14, 0, 14, 0, 1, 
	0, 0
};

static const char _foo_trans_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 7, 
	0, 0, 0, 0, 9, 0, 11, 0, 
	0, 0, 0, 1, 0, 5, 0, 0, 
	0, 0
};

static const int foo_start = 14;
static const int foo_first_final = 14;
static const int foo_error = 0;

static const int foo_en_main = 14;


/* #line 8 "example3.rl" */

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
    int cs;
    enum wordTokens returnValue = NO_WORD;


/* #line 58 "example3.rl" */

    
/* #line 105 "example3.c" */
	{
	cs = foo_start;
	}

/* #line 60 "example3.rl" */
    
/* #line 112 "example3.c" */
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
/* #line 42 "example3.rl" */
	{ returnValue = GPGGA; {p++; goto _out; } }
	break;
	case 1:
/* #line 43 "example3.rl" */
	{ returnValue = GNGSA; {p++; goto _out; } }
	break;
	case 2:
/* #line 44 "example3.rl" */
	{ returnValue = GPGSV; {p++; goto _out; } }
	break;
	case 3:
/* #line 45 "example3.rl" */
	{ returnValue = GPBOD; {p++; goto _out; } }
	break;
	case 4:
/* #line 46 "example3.rl" */
	{ returnValue = GPDBT; {p++; goto _out; } }
	break;
	case 5:
/* #line 47 "example3.rl" */
	{ returnValue = GPDCN; {p++; goto _out; } }
	break;
/* #line 207 "example3.c" */
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	p += 1;
	goto _resume;
	_out: {}
	}

/* #line 61 "example3.rl" */

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
