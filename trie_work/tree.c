//
//  tree.c
//  trie_work
//
//  Created by Joe Julicher on 1/3/19.
//  Copyright © 2019 Joe Julicher. All rights reserved.
//

#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>

struct vertex_s
{
    char letter;
    struct vertex_s *next;
};

struct edge_s
{
    int first_vertex;
    int second_vertex;
    struct edge_s *next;
};

struct vertex_s *vertex_list = NULL;
struct edge_s *edge_list = NULL;

void insert_vertex_at_end(struct vertex_s *v)
{
    if(vertex_list == NULL)
    {
        vertex_list = v;
    }
    else
    {
        struct vertex_s *vList = vertex_list;
        while(vList->next)
        {
            vList = vList->next;
        }
        vList->next = v;
        v->next = NULL;
    }
}

void insert_edge_at_end(struct edge_s *e)
{
    if(edge_list == NULL)
    {
        edge_list = e;
    }
    else
    {
        struct edge_s *eList = edge_list;
        while(eList->next)
        {
            eList = eList->next;
        }
        eList->next = e;
        e->next = NULL;
    }
}

void delete_vertex(struct vertex_s *v)
{
    // find v in the list
    if(v == vertex_list) // first in the list
    {
        vertex_list = vertex_list->next;
    }
    else
    {
        struct vertex_s *vList = vertex_list;
        struct vertex_s *pvList = NULL;
        do
        {
            pvList = vList;
            vList = vList->next;
            if(vList == v) break;
        }while(vList->next);
        pvList->next = vList->next;
    }
    free(v); // will not need to free when we get the static version.
}

void delete_edge(struct edge_s *e)
{
    // find e in the list
    if(e == edge_list) // first in the list
    {
        edge_list = edge_list->next;
    }
    else // it is someplace else in the list
    {
        struct edge_s *eList = edge_list;
        struct edge_s *peList = NULL;
        do
        {
            peList = eList;
            eList = eList->next;
            if(eList == e) break; // found it
        }while(eList->next);
        peList->next = eList->next;
    }
    free(e); // will not need to free when we get the static version.
}

void tree_insert(const char *word)
{
    
}
