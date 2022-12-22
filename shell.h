#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define EXIT_SUCCESS 0

extern char **environ;

char *_getenv(char *name);
void _cmd(char *cmd, char **argv);
char **tokenizer(char *cmd);
void exec(char **argv);
void exit_shell(void);
void handler(int i);
int env(void);
void *_calloc(unsigned int nmemb, unsigned int size);

#endif