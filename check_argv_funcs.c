#include "main.h"

/**
 * _isletter- check if value is alphabet
 * @c: character
 * Return: 0 or 1
 */
int _isletter(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
		return (1);
	else
		return (0);
}
/**
 * exit_shell - exits shell
 * @argv: array of strings
 * @input: pointer to string
 * @input_cpy: pointer to string
 *
 * Return: nothing
 */
void exit_shell(char **argv, char *input, char *input_cpy)
{
	int status;
	int i = 0;

	if (argv[1] != NULL)
	{
		while (argv[1][i])
		{
			if (_isletter(argv[1][i]))
			{
				error("illegal number");
				exit(EXIT_FAILURE);
			}
			i++;
		}
		status = _atoi(argv[1]);
		if (status < 0)
		{
			error("illegal number");
			exit(EXIT_FAILURE);
		}
		free(input);
		free(input_cpy);
		cleanup(argv);
		exit(status);
	}
	else
	{
		free(input);
		free(input_cpy);
		cleanup(argv);
		exit(0);
	}
}

/**
 * _env- prints current environment
 * @env: environment variable
 *
 * Return: 0 (success)
 */
int _env(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		_puts(env[i]);
		_putchar('\n');
	}

	return (0);
}
