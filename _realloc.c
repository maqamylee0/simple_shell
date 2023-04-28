#include "main.h"

/**
 * _realloc- reallocate space
 * @src: source pointer 
 * @dest: new space pointer
 * Return: pointer to destination
 */

char *_realloc(char *src, size_t size)
{
	char *dest;
	size_t i = 0;

	if (src == NULL)
		return (allocate(size));
	if (size == 0)
	{
		free(src);
		return (NULL);
	}
	dest = allocate(size);
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
