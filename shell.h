#ifndef _SHELL_H
#define _SHELL_H

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

/* while_loop */
int while_loop(char **av);

/* string_size */
int string_size(char *s);

/* cmd_count */
int cmd_count(char *buf);

/* splits */
char **splits(char *buf, int size);

/* str_dup */
char *str_dup(char *buf);

/* _free */
void _free(int i, ...);

/* construct */
char **construct(char *buf);

/* _strcmp */
int _strcmp(char *s1, char *s2);

/* built_func */
int (*builtin_func(char *s))();

/* is-valid */
void is_valid(char *buf, int i, char **arg, char **args);

/* pipe */
int piper(char **av __attribute__((unused)));

/* _exit */
int left(void);

/* enviroment */
int environment(void);

/* free_path */
void free_path();

/* get_path */
char **get_path();
void change_sign(char *s);

/* path_locater */
char *path_locater();

/* str_cpy */
char *str_cpy(char *s1, char *s2);

/* insert */
char *insert(char **s1, char **path);
char *concat(char *s1, char *s2);
int equate(char *s, char *s2);
char *comp(char *s, char *s2);

/* execve */
int execute(char *s1, char **arg);

#endif

