/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: gperf -t --output-file=nmea.c nmea_keywords  */
/* Computed positions: -k'2-5' */

#include <stdlib.h>
#include <string.h>

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gperf@gnu.org>."
#endif

#line 1 "nmea_keywords"
struct keyword_s {const char *name; int index;};

#define TOTAL_KEYWORDS 61
#define MIN_WORD_LENGTH 5
#define MAX_WORD_LENGTH 6
#define MIN_HASH_VALUE 41
#define MAX_HASH_VALUE 181
/* maximum key range = 141, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (register const char *str, register size_t len)
{
  static unsigned char asso_values[] =
    {
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182,  20,  15,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182,   5,   1,  21,  10,  25,
       13,  16,  56,  20, 182, 182,  26,   0,  50,  46,
       36,  30,  60,  25,  10,  55,   0,   0,   1,  55,
       21, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
      182, 182, 182, 182, 182, 182, 182
    };
  return len + asso_values[(unsigned char)str[4]] + asso_values[(unsigned char)str[3]+1] + asso_values[(unsigned char)str[2]] + asso_values[(unsigned char)str[1]];
}

struct keyword_s *in_word_set (register const char *str, register size_t len)
{
  static struct keyword_s wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 49 "nmea_keywords"
      {"GPVLW", 46},
#line 30 "nmea_keywords"
      {"GPMWV", 27},
#line 12 "nmea_keywords"
      {"GPBWW", 9},
      {""}, {""},
#line 4 "nmea_keywords"
      {"GPALM", 1},
#line 3 "nmea_keywords"
      {"GPAAM", 0},
      {""}, {""}, {""},
#line 52 "nmea_keywords"
      {"GPWCV", 49},
#line 29 "nmea_keywords"
      {"GPMWD", 26},
      {""}, {""}, {""}, {""},
#line 63 "nmea_keywords"
      {"GLGSV", 60},
      {""}, {""}, {""},
#line 48 "nmea_keywords"
      {"GPVHW", 45},
#line 46 "nmea_keywords"
      {"GPVBW", 43},
      {""},
#line 10 "nmea_keywords"
      {"GPBWC", 7},
      {""},
#line 7 "nmea_keywords"
      {"GPASD", 4},
#line 21 "nmea_keywords"
      {"GPGSV", 18},
      {""}, {""}, {""},
#line 50 "nmea_keywords"
      {"GPVPW", 47},
#line 20 "nmea_keywords"
      {"GPGSA", 17},
      {""}, {""}, {""},
#line 8 "nmea_keywords"
      {"GPBEC", 5},
#line 6 "nmea_keywords"
      {"GPAPB", 3},
#line 18 "nmea_keywords"
      {"GPGLC", 15},
      {""}, {""},
#line 5 "nmea_keywords"
      {"GPAPA", 2},
#line 13 "nmea_keywords"
      {"GPDBT", 10},
#line 19 "nmea_keywords"
      {"GPGLL", 16},
#line 16 "nmea_keywords"
      {"GPFSI", 13},
      {""},
#line 62 "nmea_keywords"
      {"GNGSA", 59},
#line 26 "nmea_keywords"
      {"GPLCD", 23},
#line 9 "nmea_keywords"
      {"GPBOD", 6},
#line 44 "nmea_keywords"
      {"GPTRF", 41},
      {""},
#line 15 "nmea_keywords"
      {"GPDPT", 12},
#line 58 "nmea_keywords"
      {"GPZDA", 55},
#line 61 "nmea_keywords"
      {"PELFID", 58},
      {""}, {""},
#line 28 "nmea_keywords"
      {"GPMTW", 25},
#line 54 "nmea_keywords"
      {"GPWPL", 51},
      {""}, {""}, {""},
#line 27 "nmea_keywords"
      {"GPMTA", 24},
#line 42 "nmea_keywords"
      {"GPSFI", 39},
#line 11 "nmea_keywords"
      {"GPBWR", 8},
      {""}, {""},
#line 45 "nmea_keywords"
      {"GPTTM", 42},
#line 32 "nmea_keywords"
      {"GPOSD", 29},
#line 53 "nmea_keywords"
      {"GPWNC", 50},
      {""}, {""},
#line 14 "nmea_keywords"
      {"GPDCN", 11},
#line 51 "nmea_keywords"
      {"GPVTG", 48},
      {""}, {""}, {""},
#line 39 "nmea_keywords"
      {"GPRSA", 36},
#line 22 "nmea_keywords"
      {"GPGXA", 19},
#line 17 "nmea_keywords"
      {"GPGGA", 14},
      {""}, {""},
#line 40 "nmea_keywords"
      {"GPRSD", 37},
#line 56 "nmea_keywords"
      {"GPXTE", 53},
      {""},
#line 59 "nmea_keywords"
      {"GPZFO", 56},
      {""},
#line 47 "nmea_keywords"
      {"GPVDR", 44},
#line 55 "nmea_keywords"
      {"GPXDR", 52},
#line 25 "nmea_keywords"
      {"GPHSC", 22},
      {""}, {""},
#line 38 "nmea_keywords"
      {"GPRPM", 35},
#line 24 "nmea_keywords"
      {"GPHDT", 21},
#line 60 "nmea_keywords"
      {"GPZTG", 57},
      {""}, {""},
#line 33 "nmea_keywords"
      {"GPR00", 30},
#line 31 "nmea_keywords"
      {"GPOLN", 28},
#line 23 "nmea_keywords"
      {"GPHDG", 20},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 37 "nmea_keywords"
      {"GPROT", 34},
      {""}, {""}, {""}, {""},
#line 35 "nmea_keywords"
      {"GPRMB", 32},
      {""}, {""}, {""},
#line 34 "nmea_keywords"
      {"GPRMA", 31},
#line 57 "nmea_keywords"
      {"GPXTR", 54},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 43 "nmea_keywords"
      {"GPSTN", 40},
#line 36 "nmea_keywords"
      {"GPRMC", 33},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 41 "nmea_keywords"
      {"GPRTE", 38}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
