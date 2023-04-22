#include "main.h"

/**
 * safe_malloc - allocates memory
 * @size: number of bytes
 *
 * Return: ptr
 */
void *safe_malloc(size_t size)
{
	void *ptr = malloc(size);

	if (!ptr)
		error("memory allocation fail");
	return (ptr);
}
