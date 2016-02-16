/*
 *
 *
 * defs.h
 * 
 * Copyright (c) {year} {name}
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar.HocevarHocevar See the COPYING file or http://www.wtfpl.net/
 * for more details.
 */

#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include "./polyaness.h"

typedef struct FLAGS_T {
    int lflag;
    int fflag;
    int nflag;
    int narg;
    char* farg;
} flags_t;

extern void release(FILE* fp, char* path, polyaness_t* polyaness);

#endif
