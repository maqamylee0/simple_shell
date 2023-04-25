#include "main.h"

/**
 * execute_command - executes command
 * @cmd_path: command path
 * @argv: double pointer to strings
 * @env: environment variable
 *
 * Return: Nothing
 */
void execute_command(char *cmd_path, char **argv, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		error(argv[0]);
	}
	else if (pid == 0)
	{
		if (execve(cmd_path, argv, env) == -1)
		{
			error(argv[0]);
		}
	}
	else
	{
		while (wait(&status) != pid)
			;
	}
}

/**
 * execute - create child process and execute
 * @argv: double pointer to strings
 * @env: environment variable
 *
 * Return: nothing
 */
void execute(char **argv, char **env)
{
	char *cmd_path;

	if (_strchr(argv[0], '/') != NULL)
	{
		execute_command(argv[0], argv, env);
	}
	else
	{
		cmd_path = get_location(argv[0]);
		if (cmd_path == NULL)
		{
			error(argv[0]);
		}
		execute_command(cmd_path, argv, env);
		free(cmd_path);
	}
}
