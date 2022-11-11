#include <stdio.h>
#include <string.h>
#include "header.h"
#include <stdlib.h>

/**
 * split_string - splits a string into words
 * @str: str to be split
 *
 * Return: array of pointers which is null terminated
 */
char **split_string(char *str)
{
	char **array, *token, delim = ' ', *saveptr;
	int ln, spaces = 2, j = 0;

	for (ln = 0; str[ln]; ln++)
	{
		if (str[ln] == ' ' && str[ln - 1] != ' ')
			spaces++;
	}
	if (ln == 1)
		return (NULL);

	str[ln - 1] = '\0';
	array = malloc(sizeof(char *) * spaces);
	for (ln = 0; ; ln++)
	{
		if ((str[ln] == ' ' && str[ln - 1] != ' ') || str[ln] == '\0')
		{
			if (j == 0)
				token = strtok_r(str, &delim, &saveptr);
			else
				token = strtok_r(NULL, &delim, &saveptr);
			if (token == NULL)
			{
				array[j] = NULL;
				break;
			}
			array[j] = malloc((strlen(token) + 1) * sizeof(char));
			strcpy(array[j], token);
			j++;
		}
	}
	return (array);
}
