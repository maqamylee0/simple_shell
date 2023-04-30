#include "main.h"

/**
 * execute - create child process and execute
 * @argv: double pointer to strings
 * @env: environment variable
 *
 * Return: nothing
 */
void execute(char **argv, char **env)
{
	int status = 0;
	char *cmd_path = NULL, *cmd = NULL;

	if (_strcmp(argv[0], "cd") == 0)
	{
		cmd = get_cd_path(argv, env);
		if (chdir(cmd) != -1)
		{
			;
		}
		return;
	}

	if (_strchr(argv[0], '/') != NULL)
	{
		execute_absolute_path(argv, env, status);
	}
	else
	{
		cmd_path = get_location(argv[0]);
		if (cmd_path == NULL)
			error(argv[0]);
		execute_cmd_path(argv, env, status, cmd_path);
	}
}
