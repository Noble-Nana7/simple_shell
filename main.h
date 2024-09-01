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
#define PATH_MAX 1024

/* Function prototypes */
void shell(char **env);
void exec_command(char *cmd, char **env);
char *read_in(void);
char *trim_ws(char *str);
void printerr(char *cmd);
char *find_cmd(char *cmd);

/* specilized exec func prototypes */
void exec_std_cmd(char *cmd);
void exec_path_cmd(char *cmd);
void exec_copy_cmd(char *cmd);
/* void exec_exit(void); */

/* helper utils prototypes for exec func */
int is_cpy(char *cmd);
int is_path(char *cmd);
int fexists(const char *path);
int isexec(const char *path);

/* More utils */
int copy_file(const char *src, const char *dest);

/* The prototypes for env */
void pr_env(char **envp);

#endif
