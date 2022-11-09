#include "header.h"

/**
 * main - prints the environment using global variable environ.
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
