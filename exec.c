#include "shell.h"

void exec(char **argv)
{
    int i;

    if (execve(argv[0], argv, environ) == -1)
        perror("");
}
