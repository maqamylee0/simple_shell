#include "main.h"

/**
 * check_argv - checks for built ins
 * @argv: array of strings
 * @env: environment variable
 * @input: pointer to string
 * @input_cpy: pointer to string
 *
 * Return: 0 (success) -1 (failure)
 */
int check_argv(char **argv, char **env, char *input, char *input_cpy)
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		exit_shell(argv, input, input_cpy);
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		_env(env);
	}
	else
	{
		return (-1);
	}
	return (0);
}
