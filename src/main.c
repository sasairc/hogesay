/*
 *
 *
 * main.c
 *
 * Copyright (c) {year} {name}
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar.HocevarHocevar See the COPYING file or http://www.wtfpl.net/
 * for more details.
 */

#include "./config.h"
#include "./defs.h"
#include "./info.h"
#include "./subset.h"
#include "./polyaness.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char* argv[])
{
    int             res     = 0,
                    index   = 0;

    FILE*           fp      = NULL; /* dict file */

    char*           path    = NULL, /* dict file path */
        *           quote   = NULL;

    polyaness_t*    pt      = NULL;

    /* flag and args */
    flags_t flags = {   
        0, 0, 0, 0 ,NULL,
    };

    struct option opts[] = {
        {"file",    required_argument, NULL, 'f'},
        {"number",  required_argument, NULL, 'n'},
        {"list",    no_argument,       NULL, 'l'},
        {"help",    no_argument,       NULL, 'h'},
        {"version", no_argument,       NULL, 'v'},
        {0, 0, 0, 0}
    };

    /* processing of arguments */
    while ((res = getopt_long(argc, argv, "f:n:lvh", opts, &index)) != -1) {
        switch (res) {
            case    'f':
                flags.farg = optarg;
                flags.fflag = 1;
                break;
            case    'n':
                if (strisdigit(optarg) < 0)
                    return -1;

                flags.narg = atoi(optarg);
                flags.nflag = 1;
                break;
            case    'l':
                flags.lflag = 1;
                break;
            case    'v':
                print_version();
            case    'h':
                print_usage();
            case    '?':
                return -1;
        }
    }

    /* concat file path */
    if ((path = concat_file_path(&flags)) == NULL)
        return 1;

    /* open flags-quotes */
    if (open_dict_file(path, &fp) < 0) {
        release(NULL, path, NULL);

        return 2;
    }

    /* read dict file */
    if (read_dict_file(fp, &pt) < 0) {
        release(NULL, path, NULL);

        return 3;
    }

    /* do parse polyaness */
    if (parse_dict_file(fp, &pt) < 0) {
        release(fp, path, pt);

        return 4;
    }

    /* 
     * print all quotes list and exit
     */
    if (flags.lflag == 1) {
        print_all_quotes(pt);
        release(fp, path, pt);

        return 0;
    }

    /*
     * generate output quote
     */
    if (flags.nflag == 0) {
        quote = get_polyaness("quote",
                create_rand(pt->recs - 1), &pt);
    } else {
        if (flags.narg < pt->recs)
            quote = get_polyaness("quote", flags.narg, &pt);
        else
            quote = get_polyaness("quote", 0, &pt);
    }

    /* print of string */
    fprintf(stdout, "%s\n", quote);

    /* release memory */
    release(fp, path, pt);

    return 0;
}

void release(FILE* fp, char* path, polyaness_t* pt)
{
    if (fp != NULL) {
        fclose(fp);
        fp = NULL;
    }
    if (path != NULL) {
        free(path);
        path = NULL;
    }
    if (pt != NULL)
        release_polyaness(pt);

    return;
}
