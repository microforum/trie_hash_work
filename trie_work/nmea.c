//
//  nmea.c
//  trie_work
//
//  Created by Joe Julicher on 12/19/18.
//  Copyright © 2018 Joe Julicher. All rights reserved.
//

#include "nmea.h"

#include "trie_search.h"
//#include "trie_builder.h"

#include "hash_builder.h"
#include <string.h>
#include <time.h>
#include "pearson_hash.h"
#include "nmea_hashmap.h"

struct key_s
{
    const char *keyword;
    const char *description;
};

const struct key_s keys[] = {
    {"GPAAM",  "Waypoint Arrival Alarm"},
    {"GPALM",  "GPS Almanac Data"},
    {"GPAPA",  "Autopilot Sentence A"},
    {"GPAPB",  "Autopilot Sentence B"},
    {"GPASD",  "Autopilot System Data"},
    {"GPBEC",  "Bearing & Distance to Waypoint, Dead Reckoning"},
    {"GPBOD",  "Bearing, Origin to Destination"},
    {"GPBWC",  "Bearing & Distance to Waypoint, Great Circle"},
    {"GPBWR",  "Bearing & Distance to Waypoint, Rhumb Line"},
    {"GPBWW",  "Bearing, Waypoint to Waypoint"},
    {"GPDBT",  "Depth Below Transducer"},
    {"GPDCN",  "Decca Position"},
    {"GPDPT",  "Depth"},
    {"GPFSI",  "Frequency Set Information"},
    {"GPGGA",  "Global Positioning System Fix Data"},
    {"GPGLC",  "Geographic Position, Loran C"},
    {"GPGLL",  "Geographic Position, Latitude/Longitude"},
    {"GPGSA",  "GPS DOP and Active Satellites"},
    {"GPGSV",  "GPS Satellites in View"},
    {"GPGXA",  "TRANSIT Position"},
    {"GPHDG",  "Heading, Deviation & Variation"},
    {"GPHDT",  "Heading, True"},
    {"GPHSC",  "Heading Steering Command"},
    {"GPLCD",  "Loran C Signal Data"},
    {"GPMTA",  "Air Temperature (to be phased out)"},
    {"GPMTW",  "Water Temperature"},
    {"GPMWD",  "Wind Direction"},
    {"GPMWV",  "Wind Speed and Angle"},
    {"GPOLN",  "Omega Lane Numbers"},
    {"GPOSD",  "Own Ship Data"},
    {"GPR00",  "Waypoint active route (not standard)"},
    {"GPRMA",  "Recommended Minimum Specific Loran C Data"},
    {"GPRMB",  "Recommended Minimum Navigation Information"},
    {"GPRMC",  "Recommended Minimum Specific GPS/TRANSIT Data"},
    {"GPROT",  "Rate of Turn"},
    {"GPRPM",  "Revolutions"},
    {"GPRSA",  "Rudder Sensor Angle"},
    {"GPRSD",  "RADAR System Data"},
    {"GPRTE",  "Routes"},
    {"GPSFI",  "Scanning Frequency Information"},
    {"GPSTN",  "Multiple Data ID"},
    {"GPTRF",  "Transit Fix Data"},
    {"GPTTM",  "Tracked Target Message"},
    {"GPVBW",  "Dual Ground/Water Speed"},
    {"GPVDR",  "Set and Drift"},
    {"GPVHW",  "Water Speed and Heading"},
    {"GPVLW",  "Distance Traveled through the Water"},
    {"GPVPW",  "Speed, Measured Parallel to Wind"},
    {"GPVTG",  "Track Made Good and Ground Speed"},
    {"GPWCV",  "Waypoint Closure Velocity"},
    {"GPWNC",  "Distance, Waypoint to Waypoint"},
    {"GPWPL",  "Waypoint Location"},
    {"GPXDR",  "Transducer Measurements"},
    {"GPXTE",  "Cross/Track Error, Measured"},
    {"GPXTR",  "Cross/Track Error, Dead Reckoning"},
    {"GPZDA",  "Time & Date"},
    {"GPZFO",  "UTC & Time from Origin Waypoint"},
    {"GPZTG",  "UTC & Time to Destination Waypoint"},
    {"PELFID", "Bad Elf Identification"},
    {"GNGSA",  "Blah Blah Blah"},
    {"GLGSV",  "I don't know"}};

#define ARRAY_SIZE(a) sizeof(a)/sizeof(*a)

void nmea_init(void)
{
    for(int x=0;x<ARRAY_SIZE(keys);x++)
    {
      //  trie_insert(keys[x].keyword, x);
    }
    //trie_export();
}

void process_a_line(const char *nmeaLine, ssize_t lineLength)
{
    bool found = false;
    char *keyword = strtok(nmeaLine,",");
    size_t length = strlen(keyword);
    clock_t start = clock();
    for(int x=0;x<ARRAY_SIZE(keys);x++)
    {
        if(strncmp(keyword,keys[x].keyword,length)==0)
        {
            found = true;
        }
    }
    clock_t string_time = clock() - start;
    start = clock();
    found=trie_search(keyword, length);
    clock_t trie_time = clock() - start;
    start = clock();
    struct keyword_s *result = in_word_set (keyword, length);
    found=result?true:false;
    clock_t hash_time = clock()-start;

    printf("%ld %ld %ld\n",string_time,trie_time,hash_time);
}

