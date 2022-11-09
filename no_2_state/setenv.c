#include "header.h"

extern char **environ;

/**
 * _setenv - changes or adds an environment variable
 * @name: name of the variable to be changed
 * @value: value to which variable is to be set to
 * @overwrite: number code which determines if the variable is to be overwritten
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0, len_name/*, len_val*/, check;
	char *str;

	if (!name)
		return (-1);
	len_name = strlen(name);
	while (*(environ + i))
	{
		if ((check = strncmp(name, *(environ + i), len_name)) == 0)
			break;
		i++;
	}
	if (check == 0 && overwrite == 0)
		return (0);
	str = strcat(strdup(name), "=");
	*(environ + 1) = strcat(str, value);
	/*free(str);*/
	return (0);
}
