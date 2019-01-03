//
//  hash_builder.c
//  trie_work
//
//  Created by Joe Julicher on 12/30/18.
//  Copyright © 2018 Joe Julicher. All rights reserved.
//

#include "hash_builder.h"
#include <string.h>
#include <stdbool.h>
#include "pearson_hash.h"

static int table_index = 1;
int hashTable[256] = {0};


int hash_make_from_string(const char *aString, ssize_t stringLength)
{
    return Pearson(aString,strlen(aString));
}

bool hash_insert(const char *keyword)
{
    int theHash = hash_make_from_string(keyword, strlen(keyword));
    int index = theHash % 256;
    if(hashTable[index])
    {
        printf("hash collision\n");
        return false;
    }
    hashTable[index] = table_index ++;
    return true;
}

int hash_search(const char *keyword, ssize_t keywordSize)
{
    int theHash = hash_make_from_string(keyword,keywordSize);
    int index = theHash % 256;
    return hashTable[index];
}
