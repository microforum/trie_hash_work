//
//  nmea_hashmap.h
//  trie_work
//
//  Created by Joe Julicher on 1/1/19.
//  Copyright © 2019 Joe Julicher. All rights reserved.
//

#ifndef nmea_hashmap_h
#define nmea_hashmap_h

struct keyword_s {const char *name; int index;};
struct keyword_s *in_word_set (register const char *str, register size_t len);

#endif /* nmea_hashmap_h */
