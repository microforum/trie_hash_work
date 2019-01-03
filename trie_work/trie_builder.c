//
//  trie_builder.c
//  trie_work
//
//  Created by Joe Julicher on 12/19/18.
//  Copyright © 2018 Joe Julicher. All rights reserved.
//

#include "trie_builder.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// C implementation of search and insert operations
// on Trie

#define MAX_NUMBER_OF_NODES 256

struct trie_s
{
    int index;
    int key_index;
};

struct trie_s trie[MAX_NUMBER_OF_NODES][26] = {0};
int next = 0;

// initially all numbers in the trie are 0 .
// assuming trie contains words with uppercase alphabet letters

void trie_insert(const char *s, int index)
{
    int t=1;
    for(int i=0;s[i];i++)
    {
        int p = s[i] - 'A';
        if(trie[t][p].index==0)
        {
            trie[t][p].index=++next;
        }
        t = trie[t][p].index;
        if(s[i+1] == 0)
        {
            trie[t][p].key_index = index+1;
        }
    }
}

int trie_search(const char *s,ssize_t length)
{
    int t=1;
    int ki = -1;
    
    for(ssize_t i=0;i < length;++i)
    {
        int p = s[i]-'A';
        if(trie[t][p].index==0)
            return -1;
        t = trie[t][p].index;
        ki = trie[t][p].key_index;
    }
    return ki-1;
}

void trie_export(void)
{
    int node_count = 0;
    bool done = false;
    printf("struct trie_s{ int index; int key_index;};\n");
    printf("struct trie_s trie[][26] = {");
    for(int x = 0; x < MAX_NUMBER_OF_NODES; x ++)
    {
        printf("{");
        for(int y=0; y < 26; y ++)
        {
            int index = trie[x][y].index;
            int key_index = trie[x][y].key_index;
            printf("{%d, %d},",index,key_index);
//            if(index || key_index) done = false;
        }
        node_count ++;
//        if(done) break;
//        done = true;
        printf("},\n");
    }
    printf("};\n");
    printf("const int MAX_NUMBER_OF_NODES = %d\n\n",node_count);
}
