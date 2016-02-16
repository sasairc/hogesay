/*
 *
 *
 * subset.h
 * 
 * Copyright (c) {year} {name}
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar.HocevarHocevar See the COPYING file or http://www.wtfpl.net/
 * for more details.
 */

#ifndef SUBSET_H
#define SUBSET_H

#include "./defs.h"
#include "./polyaness.h"
#include <stdio.h>

/* This functions is required subset.c */
extern char* concat_file_path(flags_t* flags);
extern int open_dict_file(char* path, FILE** fp);
extern int read_dict_file(FILE* fp, polyaness_t** pt);
extern int parse_dict_file(FILE* fp, polyaness_t** pt);
extern int plain_dict_to_polyaness(FILE* fp, polyaness_t** pt);
extern int strisdigit(char* str);
extern int create_rand(int lines);
extern void print_all_quotes(polyaness_t* pt);

#endif
