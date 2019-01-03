//
//  hash_builder.h
//  trie_work
//
//  Created by Joe Julicher on 12/30/18.
//  Copyright © 2018 Joe Julicher. All rights reserved.
//

#ifndef hash_builder_h
#define hash_builder_h

#include <stdio.h>
#include <stdbool.h>

bool hash_insert(const char *keyword);
int hash_make_from_string(const char *string, ssize_t stringLength);
int hash_search(const char *keyword, ssize_t keywordSize);


#endif /* hash_builder_h */
