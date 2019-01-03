//
//  nmea.h
//  trie_work
//
//  Created by Joe Julicher on 12/19/18.
//  Copyright © 2018 Joe Julicher. All rights reserved.
//

#ifndef nmea_h
#define nmea_h

#include <stdio.h>

void nmea_init(void);
void process_a_line(const char *nmeaLine, ssize_t lineLength);

#endif /* nmea_h */
