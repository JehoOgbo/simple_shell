#include "header.h"

extern char **environ;
/**
 * path_printer - prints each directory contained in environment variable path
 *
 * Return: void
 */
void path_printer(void)
{
	int i = 0;
	char delim = ':', *str, *token;

	while (*(environ + i) != NULL)
	{
		if (strncmp("PATH", *(environ + i), 4) == 0)
			break;
		i++;
	}
	str = *(environ + i);
	for (i = 0; ; i++)
	{
		if (i == 0)
			token = strtok(str, &delim);
		else
			token = strtok(NULL, &delim);
		if (token == NULL)
		{
			break;
		}
		if (i != 0)
			printf("%s\n", token);
	}
}
