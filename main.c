#include "main.h"

/**
 * run_interactive - runs interactive mode
 *
 * Return: nothing
 */
void run_interactive_mode(void)
{
	char *prompt = "$";
	char *input = NULL, *input_cpy;
	char **argv;
	const char *delim = " \n";
	ssize_t nchars_read;
	extern char **environ;
	char **env = environ;
	size_t n = 0;
	int num_tokens;

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

		argv = parse_input(input, delim, &num_tokens);

		num_tokens = num_token(input_cpy, delim);
		if (num_tokens != 2)
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
 *
 * Return: nothing
 */
void run_non_interactive_mode(void)
{
	char *input = NULL, *input_cpy;
	char **argv;
	const char *delim = " \n";
	ssize_t nchars_read;
	extern char **environ;
	char **env = environ;
	size_t n = 0;
	int num_tokens;

	while (1)
	{
		nchars_read = getline(&input, &n, stdin);
		if (nchars_read == -1)
		{
			break;
		}
		input_cpy = allocate(nchars_read);
		_strcpy(input_cpy, input);

		argv = parse_input(input, delim, &num_tokens);

		num_tokens = num_token(input_cpy, delim);
		if (num_tokens != 2)
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
 *
 * Return: 0 (success)
 */
int main()
{
	if (isatty(STDIN_FILENO))
	{
		run_interactive_mode();
	}
	else
	{
		run_non_interactive_mode();
	}
	return (0);
}
