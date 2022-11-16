#include "header.h"

/**
 * _unsetenv - unsets an environment variable
 * @name: name of the variable to be unset
 * @environ: local environment to be edited
 * @excess: should always be null for function to run properly
 *
 * Return: 0 or -1
 */
int _unsetenv(const char *name, char **environ, char *excess)
{
	int i = 0, j = 0, len = strlen(name);

	if (!name || excess)
	{
		fprintf(stderr, "Wrong input. Usage: unsetenv VARIABLE\n");
		return (-1);
	}
	if (len == 0)
		return (-1);
	while (name[j])
	{
		if (name[j] == '=')
			return (-1);
		j++;
	}
	while (*(environ + i) != NULL)
	{
		if (strncmp(name, *(environ + i), len) == 0)
			break;
		i++;
	}
	if (*(environ + i) == NULL)
	{
		printf("Error");
		return (0);
	}
	while (*(environ + i) != NULL)
	{
		*(environ + i) = *(environ + i + 1);
		i++;
	}
	return (0);
}
