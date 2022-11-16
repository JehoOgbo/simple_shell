#include "header.h"

/**
 * free_env - frees all environment variables added during running program
 * @env: list of environment variables
 * @number: original number of environment variables
 *
 * Return: void
 */
void free_env(char **env, int number)
{
	while (*(env + number))
	{
		free(*(env + number));
		number++;
	}
}
