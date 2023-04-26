#include "main.h"

/**
 * check_argv - checks for built ins
 * @argv: array of strings
 * @env: environment variable
 *
 * Return: 0 (success) -1 (failure)
 */
int check_argv(char **argv, char **env)
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		exit_shell(argv);
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
