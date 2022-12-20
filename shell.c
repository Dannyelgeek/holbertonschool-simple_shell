#include "shell.h"

int main(void)
{
	size_t size = 1024;
	pid_t pid;
	char *buff = malloc(sizeof(char) * size);
	int val;
	
	if (!buff)
		return (0);
	while(1)
	{
		printf("$ ");
		val = getline(&buff, &size, stdin);

		if(val == -1)
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
			wait(NULL);
	}
	free(buff);
	return (0);
}
