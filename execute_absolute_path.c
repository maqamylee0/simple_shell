#include "main.h"

/**
 * execute_absolute_path - executes absolute path
 * @argv: double pointer to strings
 * @env: environment variable
 * @status: status of process
 *
 * Return: nothing
 */
void execute_absolute_path(char **argv, char **env, int status)
{
	pid_t pid = fork();

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
