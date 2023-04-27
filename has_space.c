#include "main.h"

/**
 * has_space - checks for spaces
 * @input: string to check
 *
 * Return: 1 or 0 (true or false)
 */
int has_space(char *input)
{
	int i;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] != ' ')
		{
			return (0);
		}
	}
	return (1);
}
