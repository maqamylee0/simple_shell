#include "main.h"

/**
 * parse_input - parses input
 * @input: input string
 * @delim: deliminator
 * @num_tokens: number of tokens
 *
 * Return: double pointer
 */
char **parse_input(char *input, const char *delim, int *num_tokens)
{
	char *token, *input_copy;
	int i;
	char **argv;

	input_copy = _strdup(input);
	if (!input_copy)
		error("string duplication error");
	*num_tokens = 0;
	token = _strtok(input_copy, delim);
	while (token)
	{
		(*num_tokens)++;
		token = _strtok(NULL, delim);
	}

	argv = safe_malloc(sizeof(char *) * ((*num_tokens) + 1));
	token = _strtok(input, delim);
	for (i = 0; token; i++)
	{
		argv[i] = safe_malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(argv[i], token);
		token = _strtok(NULL, delim);
	}
	argv[i] = NULL;

	free(input_copy);

	return (argv);
}
