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
        printf("$ ");
        val = getline(&buff, &size, stdin);
        if (val == -1)
        {
            printf("exit\n");
            exit(-1);
        }
        pid = fork();
        if (!pid)
        {
            tokenizer(buff);
            break;
        }
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
