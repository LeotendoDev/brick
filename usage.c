/********************************************
 *
 * FILE - usage.c
 *
 * by Leonard Steinhoff
 * created at: Do Apr 07 15:45 JST 2022
 *
 * licensed under MIT
 *
 * Copyright (c) 2021-2022 Leonard Steinhoff
 *
 *
 ********************************************
*/

#include <stdlib.h>
#include <brick/usage.h>

void bc_print_opt(char* opt, char* job, FILE* std)
{
    printf("  %s   %s\n", opt, job);
}

void bc_usage(int err)
{
    FILE* dest = err ? stderr : stdout;

    fprintf(dest, "Usage: brick [options] file...\n");
    fprintf(dest, "Options:\n");
    bc_print_opt("-p", "Changes include path", dest);
    bc_print_opt("-o", "Changes the output path", dest);
    bc_print_opt("-u", "Enable unsafe memory", dest);

    exit(err ? -1 : 0);
}
