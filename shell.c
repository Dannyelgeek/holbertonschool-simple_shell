#include "shell.h"

/**
 * main - creates a prompt and awaits for commands.
 * Return: 0 if exited correctly.
 */

int main(void)
{
	size_t size = 1024;
	pid_t pid;
	char *buff;
	int val;
	int status;

	signal(SIGINT, handler);

	while (1)
	{
		buff = malloc(sizeof(char) * size);
		if (!buff)
			return (0);

		if (isatty(STDIN_FILENO))
			printf("Holy_Shell> ");
		val = getline(&buff, &size, stdin);
		if (strcmp(buff, " ") == 0)
        {
            free(buff);
            continue;
        }
		if (strcmp(buff, "\n") == 0)
        {
            free(buff);
            continue;
        }
		if (val == -1)
		{
			free(buff);
			exit(WEXITSTATUS(status));
		}
		if (_strcmp(buff, "exit\n") == 0)
		{
			free(buff);
			exit(WEXITSTATUS(status));
		}
		if (_strcmp(buff, "env\n") == 0)
		{
			env();
			continue;
		}
		pid = fork();
		if (!pid)
			tokenizer(buff);
		else
			wait(&status);
		free(buff);
	}
	return (0);
}

/**
 * handler - Goes back to prompt after typing ^C.
 * @i: variable.
 */

void handler(int i)
{
	if (i)
	{
		write(STDOUT_FILENO, "\nHoly_Shell> ", _strlen("\nHoly_Shell> "));
	}
}
