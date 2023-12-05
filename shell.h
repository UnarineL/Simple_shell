#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 64

int _strlen(char *s);
void prompt(void);
char *read_line(void);
char **parse_input(char *input);
void exe_cmd(char *command);
void free_args(char **args);
int _printf(const char *format, ...);
#endif
