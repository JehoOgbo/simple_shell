#include "header.h"

/**
 * _printenv - prints the environment using global variable environ.
 * @environ: local environment of the shell
 *
 * Return: 0 always success
 */
void _printenv(char **environ)
{
	int i = 0;

	while (*(environ + i) != NULL)
	{
		printf("%s\n", *(environ + i));
		i++;
	}
}
