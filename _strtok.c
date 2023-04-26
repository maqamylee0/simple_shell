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
	int i = 0;
	static char *count;
	char *token = NULL;

	if (delim == NULL)
		return (NULL);
	if (str == NULL && *count == '\0')
	{
		count = NULL;
		return (NULL);
	}
	if (str != NULL && count == NULL)
	{
		token = allocate(_strlen(str));
		count = _strdup(str);
	}
	if (str == NULL && *count == *delim)
	{
		i++;
		token = allocate(_strlen(count));
	}
	while ((count[i] != *delim) && (count[i] != '\0'))
	{
		token[i] = count[i];
		i++;
	}
	token[i] = '\0';
	count = &count[i];
	return (token);
}
