#include "main.h"

/**
 * _getline- get input from user
 * @lineptr: double pointer to buffer
 * @n: pointer to size of buffer
 * @stream: input from keyboard
 *
 * Return: number of bytes read
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t bytes_read = 0;
	char *buffer = NULL;
	size_t buffer_size = *n;
	size_t read_bytes = 0;
	int fd = fileno(stream);
	char *buffer_loc = NULL;

	while (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	buffer = allocate(buffer_size);
	buffer_loc = buffer;
	if (buffer_size == 0)
	{
		buffer_size = 100;
	}
	while ((bytes_read = read(fd, buffer_loc, buffer_size - read_bytes)) > 0)
	{
		read_bytes += bytes_read;
		if (read_bytes >= buffer_size)
		{
			buffer_size *= 2;
			buffer = realloc(buffer, buffer_size);
			if (buffer == NULL)
				return (-1);
		}
		if (buffer[read_bytes - 1] == '\n')
			break;
		buffer_loc += read_bytes;
	}
	if (bytes_read == -1 || bytes_read == 0)
	{
		free(buffer);
		return (-1);
	}
	buffer[read_bytes] = '\0';
	*lineptr = buffer;
	*n = buffer_size;
	return (read_bytes);
}
