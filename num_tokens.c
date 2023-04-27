#include "main.h"

/**
 * num_token - calculates number of tokens
 * @str: string to be tokenized
 * @delim: deliminator
 *
 * Return: number of tokens
 */
int num_token(char *str, const char *delim)
{
	char *token;
	int token_num;

	token = strtok(str, delim);

	token_num = 0;
	while (token != NULL)
	{
		token_num++;
		token = strtok(NULL, delim);
	}
	return (token_num);
}
