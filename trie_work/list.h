//
//  list.h
//  trie_work
//
//  Created by Joe Julicher on 1/3/19.
//  Copyright © 2019 Joe Julicher. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>



void list_insert_at_head(struct list_s *item);
void list_insert_at_tail(struct list_s *item);
void list_insert_after_item(struct list_s *afterMe, struct list_s *item);


#endif /* list_h */
