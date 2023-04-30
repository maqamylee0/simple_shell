#include "main.h"

/**
 * execute_cmd_path - executes cmd_path
 * @argv: double pointer to strings
 * @env: environment variable
 * @status: process state
 * @cmd_path: string with command
 *
 * Return: nothing
 */
void execute_cmd_path(char **argv, char **env, int status, char *cmd_path)
{
	pid_t pid = fork();

	if (pid == -1)
		error(argv[0]);
	else if (pid == 0)
	{
		if (execve(cmd_path, argv, env) == -1)
			error(argv[0]);
	}
	else
	{
		while (wait(&status) != pid)
			;
	}
	free(cmd_path);
}
