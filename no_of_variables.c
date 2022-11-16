#include "header.h"

/**
 * no_env - finds no of environment variables in order to remove memory leaks
 * @environ: array of pointers to the environment variables
 *
 * Return: number of environment variables
 */
int no_env(char **environ)
{
	int i = 0;

	while (*(environ + i))
	{
		i++;
	}
	return (i);
}
