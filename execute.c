#include "main.h"

/**
 * execute - create child process and execute
 * @argv: double pointer to strings
 * @env: environment variable
 * Return: nothing
 */
void execute(char **argv, char **env)
{
	pid_t pid;
	int status;
	char *cmd_path = NULL;

	if (strchr(argv[0], '/') != NULL)
	{
		pid = fork();
		if (pid == -1)
			error(argv[0]);
		else if (pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				error(argv[0]);
		}
		else
		{
			while (wait(&status) != pid)
				;
		}
	}
	else
	{
		cmd_path = get_location(argv[0]);
		if (cmd_path == NULL)
			error(argv[0]);
		pid = fork();
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
}
