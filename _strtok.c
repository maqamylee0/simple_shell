#include "main.h"

/**
 * _strtok- separates string into tokens
 * @str: string to separate
 * @delim: delimeter
 *
 * Return: pointer to next token
 */

char *_strtok(char *str, const char *delim)
{
	const char *c;
	static char *next_token;
	char *current_token = NULL;

	if (str)
		next_token = str;
	while (*next_token)
	{
		for (c = delim; *c; ++c)
		{
			if (*next_token == *c)
				break;
		}
		if (!*c)
		{
			break;
		}
		++next_token;
	}
	if (!*next_token)
		return (NULL);
	current_token = next_token;

	while (*next_token)
	{
		for (c = delim; *c; ++c)
		{
			if (*next_token == *c)
				break;
		}
		if (*c)
			break;
		++next_token;
	}
	if (*next_token)
		*next_token++ = '\0';

	return (current_token);
}
