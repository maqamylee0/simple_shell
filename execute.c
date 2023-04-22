#include "main.h"

/**
 * execute - create child process and execute
 * @argv: double pointer to strings
 *
 * Return: nothing
 */
void execute(char **argv, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			perror("execve failed");
			exit(1);
		}
	}
	else
	{
		while (wait(&status) != pid)
			;
	}
}
