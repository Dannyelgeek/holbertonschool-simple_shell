#include "shell.h"

/**
 * _strdup - duplicates a string.
 * @src: string to compare.
 * Return: dup if exited correctly.
*/

char *_strdup(const char *src)
{
	int x, y;
	char *dup;

	for (x = 0; src[x] != '\0';)
		x++;
	dup = malloc(sizeof(char) * (x + 1));
	if (dup == NULL)
		return (NULL);
	for (y = 0; src[y] != '\0'; y++)
	{
		dup[y] = src[y];
	}
	return (dup);
}
