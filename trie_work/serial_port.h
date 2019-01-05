//
//  serial_port.h
//  trie_work
//
//  Created by Joe Julicher on 12/21/18.
//  Copyright © 2018 Joe Julicher. All rights reserved.
//

#ifndef serial_port_h
#define serial_port_h

#include <stdio.h>

int serial_open(void);
size_t serial_write(char *data, size_t length);
size_t serial_read(char *data, size_t length);
void serial_close(void);

#endif /* serial_port_h */
