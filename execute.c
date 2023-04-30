#include "main.h"
/**
 * change_dir- changes directory
 * @argv: input arguments
 * @env: environment
 * Return: void
 */
void change_dir(char **argv, char **env)
{
	char current_dir[PATH_MAX];
	char *cmd = NULL;

	cmd = get_cd_path(argv, env);
	if (chdir(cmd) != -1)
	{
		getcwd(current_dir, sizeof(current_dir));
		setenv("OLDPWD", _getenv("PWD", env), 1);
		setenv("PWD", current_dir, 1);
	}
	_puts(cmd);
	_putchar('\n');
}
/**
 * fork_exec- child process
 * @argv: arguments
 * @env: environment
 * @cmd: command to execute or path
 *
 * Return: void
 */
void fork_exec(char *cmd, char **argv, char **env)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == -1)
		error(argv[0]);
	else if (pid == 0)
	{
		if (execve(cmd, argv, env) == -1)
			error(argv[0]);
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
 * Return: nothing
 */
void execute(char **argv, char **env)
{
	char *cmd_path = NULL;

	if (_strcmp(argv[0], "cd") == 0)
	{
		change_dir(argv, env);
		return;
	}
	if (_strchr(argv[0], '/') != NULL)
		fork_exec(argv[0], argv, env);
	else
	{
		cmd_path = get_location(argv[0]);
		if (cmd_path == NULL)
			error(argv[0]);
		fork_exec(cmd_path, argv, env);
	}
	free(cmd_path);
}
