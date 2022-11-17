#ifndef _SIMPLE_SHELL_H
#define _SIMPLE_SHELL_H

extern char **environ;

/* standard libraries to be used */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdarg.h>

/**
 * struct built - a struct that holds build in cmds
 * @b_n: cmd name
 * @b_f: ptr to a func
 */
 typedef struct built
 {
 	char *b_n;
 	int (*b_f)();
 } b_s;

int while_loop(char **av);
int cmd_count(char *buf);
char **splits(char *buf, int size);
char *str_dup(char *buf);
void _free(int i, ...);
char **construct(char *buf);
int _strcmp(char *s1, char *s2);
int (*builtin_func(char *s))();
void is_valid(char *buf, int i, char **arg, char **args);
int piper(char **av __attribute__((unused)));
int left(void);
int environment(void);
void free_path();
char **get_path();
char *path_locater();
char *str_cpy(char *s1, char *s2);
void change_sign(char *s);
char *insert(char **s1, char **path);
int execute(char *s1, char **arg);

#endif
