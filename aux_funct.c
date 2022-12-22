#include "shell.h"

/**
*  _strcmp -  prints a concatenate string.
* @s1: character to check.
* @s2: sttring to concatenate.
* Return: dest if exited correctly, non-zero otherwise.
*/

int _strcmp(char *s1, char *s2)
{
	int com, iq = 0;

	while (s1[iq] != '\0')
	{
		iq += 1;
	}

	com = 0;

	while (com < iq)
	{
		if (s1[com] != s2[com])
		{
			return (s1[com] - s2[com]);
		}
		com++;
	}
	return (0);
}

/**
* _strlen -  returns the length of a string.
* @s: character to check.
* Return: 0 if exited correctly, non-zero otherwise.
*/

int _strlen(char *s)
{
	int c = 0;

	while (s[c] != '\0')
		c++;
	return (c);
}

/**
 * _strncmp - code
 * @s1: pointer
 * @s2: pointer
 * n: 
 * Return: 0
 */

int _strncmp(char *s1, char *s2, int n)
{
    int x;
    x = 0;
    while (x < n)
    {
        if (s1[x] != s2[x])
        {
            return (s1[x] - s2[x]);
        }
        x++;
    }
    return (0);
}

/**
*  *_strcpy -  prints a copy of the string.
* @src: character to check.
* @dest: sttring to copy.
* Return: dest if exited correctly, non-zero otherwise.
*/

char *_strcpy(char *dest, char *src)
{
	int lec = 0, cop = 0;

	while (src[lec] != '\0')
	{
		lec += 1;
	}

	for (cop = 0; cop < lec; cop++)
	{
		dest[cop] = src[cop];
	}
	dest[cop] = '\0';

	return (dest);
}

/**
*  *_strcat -  prints a concatenate string.
* @src: character to check.
* @dest: sttring to concatenate.
* Return: dest if exited correctly, non-zero otherwise.
*/

char *_strcat(char *dest, char *src)
{
	int con, cat = 0, ten = 0;

	while (dest[cat] != '\0')
	{
		cat += 1;
	}

	while (src[ten] != '\0')
	{
		ten += 1;
	}

	for (con = cat; con < (cat + ten); con++)
	{
		*(dest + con) = *(src + (con - cat));
	}
	return (dest);
}
