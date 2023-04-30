#include "main.h"

/**
 * get_cd_path - gets path for cd
 * @argv: array of arguments
 * @env: environment variable
 *
 * Return: path to change directory to
 */
char *get_cd_path(char **argv, char **env)
{
	char *path = NULL;

	if (argv[1] == NULL)
	{
		path = _getenv("HOME", env);
	}
	else if (_strcmp(argv[1], "-") == 0)
	{
		path = _getenv("OLDPWD", env);
	}
	else
	{
		path = argv[1];
	}
	return (path);
}
