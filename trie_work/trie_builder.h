//
//  trie_builder.h
//  trie_work
//
//  Created by Joe Julicher on 12/19/18.
//  Copyright © 2018 Joe Julicher. All rights reserved.
//

#ifndef trie_builder_h
#define trie_builder_h

#include <stdio.h>
#include <stdbool.h>


int trie_search(const char *s,ssize_t length);
void trie_insert(const char *s, int index);
void trie_export(void);

#endif /* trie_builder_h */
