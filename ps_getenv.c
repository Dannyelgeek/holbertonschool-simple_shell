#include "shell.h"

char *_getenv(char *name)
{
    int i = 0;
    char *val;

    unsigned long lenValue, lenName = strlen(name);

    while (environ[i] != NULL)

    {
        lenValue = strlen(environ[i]);
        val = malloc(lenValue * sizeof(char));
        if (val == NULL)
        {
            perror("failed to allocate value");
            return (NULL);
        }
        if (strncmp(name, environ[i], lenName) == 0 && strcpy(val, environ[i]))
        {
            return (val);
        }
        free(val);
        i++;
    }
    free(val);
    return (NULL);
}

/*void exit_shell(void)
{
    exit(EXIT_SUCCESS);
}*/

void _cmd(char *cmd, char **argv)
{
    char *tkn = NULL, *cp_path = NULL, *path = cmd;
    struct stat st;

    cp_path = strdup(_getenv("PATH"));
    tkn = strtok(cp_path, "=");
    tkn = strtok(NULL, "\0");
    tkn = strtok(tkn, ":");

    while (tkn && stat(path, &st) != 0)
    {
        path = malloc(sizeof(char) * strlen(tkn) + strlen(cmd) + 1);
        strcat(path, tkn), strcat(path, "/"), strcat(path, cmd);

        tkn = strtok(NULL, ":");
    }
    argv[0] = strdup(path);
    exec(argv);
}
