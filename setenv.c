#include "header.h"

/**
 * _setenv - changes or adds an environment variable
 * @name: name of the variable to be changed
 * @value: value to which variable is to be set to
 * @environ: local environment of shell to which changes will be made
 * @arg: should be null or function fails
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value, char **environ, char *arg)
{
	int i = 0, len_name;
	char *str;

	if (arg || !value || !name)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}
	len_name = strlen(name);
	while (*(environ + i))
	{
		if (strncmp(name, *(environ + i), len_name) == 0)
			break;
		i++;
	}
	str = strcat(strdup(name), "=");
	*(environ + i) = strcat(str, value);
	*(environ + i + 1) = NULL;
	return (0);
}
