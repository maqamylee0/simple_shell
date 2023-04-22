#include "main.h"

/**
 * cleanup - frees argv
 * @argv: double pointer to clean up
 *
 * Return: nothing
 *
 */
void cleanup(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
	free(argv);
}
