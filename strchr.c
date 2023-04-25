#include "main.h"

/**
 * _strchr - function that locates a character in a string
 * @s: string to be searched
 * @c: sought after ninja
 * Return: &(s[i] = c) or NULL
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0 ; s[i] != '\0' ; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}
