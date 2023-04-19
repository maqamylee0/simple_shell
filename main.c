#include "main.h"

/**
 * call_fork- create a child process
 * @pid: return of process creation
 * @argv: list of arguments
 * @env: environment variables
 * Return: 0 or -1
 */

int call_fork(pid_t pid, char **argv, char **env)
{
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		int exec = execve(argv[0], argv, env);

		if (exec == -1)
			printf("No such file or directory");
	}
	return (0);
}

/**
 * main- starting function
 * @ac: number of arguments
 * @argv: array of pointers to strings
 *
 * Return: 0 for success or non zero for failure
 *
 */


int main(int ac, char **argv)
{
	char *shell_prompt = "simple_shell $: ";
	char *input_ptr = NULL;
	char *str_copy = NULL;
	ssize_t read;
	size_t n = 0;
	char *token = NULL;
	const char *delim = " \n";
	char **env = environ;
	pid_t pid;

	argc = 0;
	while (1)
	{
		printf("%s", shell_prompt);
		read = getline(&input_ptr, &n, stdin);
		if (read == -1)
			return (-1);
		str_copy = malloc(sizeof(char) * n);
		strcpy(str_copy, input_ptr);
		token = strtok(str_copy, delim);
		argv[0] = token;
		while (token)
		{
			token = strtok(NULL, delim);
			argc++;
			argv[argc - 1] = token;
		}
		argv[argc] = NULL;
		int ret = call_fork(pid, argv, env);

		if (ret == -1)
			return (-1);
		wait(NULL);
	}
	free(str_copy);
	return (0);
}
