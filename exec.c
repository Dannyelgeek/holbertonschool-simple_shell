#include "shell.h"

void exec(char **argv)
{
    if (execve(argv[0], argv, environ) == -1)
        perror(argv[0]);
}
