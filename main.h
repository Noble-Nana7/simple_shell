#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * Function protypes
 */
void prompt(void);
char *readin(void);
char **tokenin(char *input);
int exec_command(char **args);

#endif
