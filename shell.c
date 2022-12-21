#include "shell.h"
int main(void)
{
    size_t size = 1024;
    pid_t pid;
    char *buff = malloc(sizeof(char) * size);
    int val;
    int status;

    if (!buff)
        return (0);

    signal(SIGINT, handler);

    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("$ ");
        val = getline(&buff, &size, stdin);
        if (val == -1)
        {
            exit(WEXITSTATUS(status));
        }
        if (strcmp(buff, "exit\n") == 0)
            exit(WEXITSTATUS(status));
        if (strcmp(buff, "env\n") == 0)
        {
            env();
            continue;
        }
        pid = fork();
        if (!pid)
            tokenizer(buff);
        else
            wait(&status);
    }
    free(buff);
    return (0);
}

void handler(int i)
{
    if (i)
    {
        write(STDOUT_FILENO, "\n$ ", strlen("\n$ "));
    }
}
