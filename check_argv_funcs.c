#include "main.h"

/**
 * exit_shell - exits shell
 *
 * Return: nothing
 */
void exit_shell(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * _env- prints current environment
 * @env: environment variable
 *
 * Return: 0 (success)
 */
int _env(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
		_puts(env[i]);

	return (0);
}
