#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>
#include <errno.h>

#define PROMPT "Nana$ "

/* Function prototypes */
void shell(void);
void exec_command(char *cmd);
char *read_in(void);
char *trim_ws(char *str);
void printerr(char *cmd);

#endif
