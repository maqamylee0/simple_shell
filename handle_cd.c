#include "main.h"

/**
 * handle_cd- handles cd
 * @argv: list of arguments
 * Return: 0 or 1
 */

int handle_cd(char **argv)
{
	char path[1024];
	int cd_val = 0;


	if (argv[1] == NULL)
		cd_val = chdir(getenv("HOME"));
	if (_strcmp(argv[1], "-") == 0)
		cd_val = chdir(getenv("OLDPWD"));
	else
		cd_val = chdir(argv[1]);
	if (cd_val == -1)
	{
		perror("Failed to change diretory");
		return (-1);
	}
	if (getcwd(path, sizeof(path)) == NULL)
	{
		perror("Failed to change directory");
		return (-1);
	}
	if (setenv("OLDPWD", getenv("PWD"), 1) == -1)
	{
		perror("Failed to change directory");
		return (-1);
	}
	if (setenv("PWD", path, 1) == -1)
	{
		perror("Failed to change directory");
		return (-1);
	}
	return (0);
}
