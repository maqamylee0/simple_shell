#include "main.h"

/**
 * error - displays error and exits
 * @msg: error message
 *
 * Return: void
 */
void error(char *msg)
{
	perror(msg);
}
