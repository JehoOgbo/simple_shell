#include "header.h"

extern char **environ;
/**
 * _getenv - gets an environment variable without using getenv
 * @name: name of the variable to be found
 *
 * Return: the variable and value
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t len;

	len = strlen(name);

	while (*(environ + i) != NULL)
	{
		if (strncmp(name, *(environ + i), len) == 0)
			return (*(environ + i));
		i++;
	}
	return (NULL);
}
