#include "main.h"

/**
 * _getenv - gets an environment variable
 * @name: name of the variable
 * @env: environment variables
 *
 * Return: pointer to variable or NULL (not found)
 */
char *_getenv(const char *name, char **env)
{
	char *value = NULL;
	char *temp;
	int i, j;

	i = 0;
	while (env[i] != NULL)
	{
		j = 0;
		temp = env[i];
		while (name[j] != '\0' && name[j] == temp[j])
			j++;
		if (name[j] == '\0' && temp[j] == '=')
		{
			value = temp + j + 1;
			break;
		}
		i++;
	}
	return (value);
}
