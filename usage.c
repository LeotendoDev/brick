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

#include <stdio.h>
#include <stdlib.h>
#include <brick/usage.h>

void bc_print_opt(char* opt, char* job)
{
    printf("%s   %s\n", opt, job);
}

void bc_usage(int err)
{
    FILE* dest = err ? stderr : stdout;
    bc_print_opt("-I", "Change include path"); 

    exit(err ? -1 : 0);
}
