#include "main.h"

/**
 * allocate - function that allocates memory using malloc
 * @n: number of bytes
 *
 * Return: pointer (success) or NULL
 */
char *allocate(int n)
{
	char *buff = malloc(sizeof(char) * n);

	if (!buff)
	{
		perror("memory allocation error");
		return (NULL);
	}
	return (buff);
}
