#include "shell.h"

/**
 * tokenizer - tokenizes all arguments given in the prompt.
 * @cmd: all arguments passed like commands and flags.
 * Return: NULL if exited correctly.
 */

char **tokenizer(char *cmd)
{
	char *cmdcpy = NULL, *token = NULL;
	char **argv = NULL;
	int argc = 0, i = 0;
	struct stat st;

	cmdcpy = _strdup(cmd);
	token = strtok(cmd, " \n");

	while (token)
	{
		token = strtok(NULL, " \n");
		argc++;
	}

	argv = (char **)malloc(sizeof(char *) * (argc + 1));
	token = strtok(cmdcpy, " \n");

	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	argv[i] = NULL;

	if (argv[0][0] == '/' && stat(cmd, &st) == 0)
		exec(argv);

	_cmd(argv[0], argv);
	return (NULL);
}
