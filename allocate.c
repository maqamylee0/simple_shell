#include "main.h"

/**
 * allocate - function that allocates memory using malloc
 * @n: number of bytes
 *
 * Return: pointer (success) or NULL
 */
char *allocate(int n)
{
	int i;
	char *buff = malloc(sizeof(char) * n + 1);

	if (!buff)
	{
		perror("memory allocation error");
		return (NULL);
	}
	for (i = 0; i < n; i++)
	{
		buff[i] = 0;
	}
	return (buff);
}
