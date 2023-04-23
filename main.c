#include "main.h"

/**
 * run_interactive_mode - runs interactive mode
 * @argc: number of arguments passed to shell
 * @argv: string holding arguments
 * @envp: environment variable
 *
 * Return: nothing
 */
void run_interactive_mode(int argc, char **argv, char **envp)
{
	char *prompt = "$";
	char *input = NULL, *input_cpy;
	const char *delim = " \n";
	ssize_t nchars_read;
	char **env = envp;
	size_t n = 0;

	while (1)
	{
		_puts(prompt);
		nchars_read = getline(&input, &n, stdin);
		if (nchars_read == -1)
		{
			exit(1);
		}
		input_cpy = allocate(nchars_read);
		_strcpy(input_cpy, input);

		argv = parse_input(input, delim, &argc);

		argc = num_token(input_cpy, delim);
		if (argc != 2)
		{
			perror("many tokens");
		}
		else
		{
			execute(argv, env);
		}
		cleanup(argv);
	}
	free(input);
}

/**
 * run_non_interactive_mode - run non-interactive mode
 * @argc: number of arguments passed to shell
 * @argv: string holding arguments
 * @envp: environment variable
 *
 * Return: nothing
 */
void run_non_interactive_mode(int argc, char **argv, char **envp)
{
	char *input = NULL, *input_cpy;
	const char *delim = " \n";
	ssize_t nchars_read;
	char **env = envp;
	size_t n = 0;

	while (1)
	{
		nchars_read = getline(&input, &n, stdin);
		if (nchars_read == -1)
		{
			break;
		}
		input_cpy = allocate(nchars_read);
		_strcpy(input_cpy, input);

		argv = parse_input(input, delim, &argc);

		argc = num_token(input_cpy, delim);
		if (argc != 2)
		{
			perror("many tokens");
		}
		else
		{
			execute(argv, env);
		}
		cleanup(argv);
	}
	free(input);
}

/**
 * main - simple shell
 * @argc: number of arguments passed to main function
 * @argv: double pointer to arguments in string format
 * @envp: environment variable
 *
 * Return: 0 (success)
 */
int main(int argc, char **argv, char **envp)
{
	if (isatty(STDIN_FILENO))
	{
		run_interactive_mode(argc, argv, envp);
	}
	else
	{
		run_non_interactive_mode(argc, argv, envp);
	}
	return (0);
}
