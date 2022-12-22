#include "shell.h"

char *_getenv(char *name)
{
	int i = 0;
	char *val;

	unsigned long lenValue, lenName = _strlen(name);

	while (environ[i] != NULL)

	{
		lenValue = _strlen(environ[i]);
		val = malloc(lenValue * sizeof(char));
		if (val == NULL)
		{
			perror("failed to allocate value");
			return (NULL);
		}
		if (_strncmp(name, environ[i], lenName) == 0 && _strcpy(val, environ[i]))
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

	cp_path = _strdup(_getenv("PATH"));
	tkn = strtok(cp_path, "=");
	tkn = strtok(NULL, "\0");
	tkn = strtok(tkn, ":");

	while (tkn && stat(path, &st) != 0)
	{
		path = malloc(sizeof(char) * _strlen(tkn) + _strlen(cmd) + 1);
		_strcat(path, tkn), _strcat(path, "/"), _strcat(path, cmd);

		tkn = strtok(NULL, ":");
	}
	argv[0] = _strdup(path);
	exec(argv);
	free(path);
}

int env(void)
{
	int i;
	extern char **environ;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);

	return (0);
}

void exec(char **argv)
{
	if (execve(argv[0], argv, environ) == -1)
		perror("not found");
}
