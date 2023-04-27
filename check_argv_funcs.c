#include "main.h"

/**
 * exit_shell - exits shell
 * @argv: array of strings
 * @input: pointer to string
 * @input_cpy: pointer to string
 *
 * Return: nothing
 */
void exit_shell(char **argv, char *input, char *input_cpy)
{
	int status;

	if (argv[1] != NULL)
	{
		status = _atoi(argv[1]);
		free(input);
		free(input_cpy);
		cleanup(argv);
		exit(status);
	}
	else
	{
		free(input);
		free(input_cpy);
		cleanup(argv);
		exit(0);
	}
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
