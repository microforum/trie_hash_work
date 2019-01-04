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
#include <unistd.h>

int serial_open(void);
ssize_t serial_write(char *data, ssize_t length);
ssize_t serial_read(char *data, ssize_t length);
void serial_close(void);

#endif /* serial_port_h */
