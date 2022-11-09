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
	char **array, *token, delim = ' ';
	int len, spaces = 2, j = 0;

	for (len = 0; str[len]; len++)
	{
		if (str[len] == ' ' && str[len - 1] != ' ')
			spaces++;
	}

	array = malloc(sizeof(char *) * spaces);
	for (len = 0; ; len++)
	{
		if (str[len] == ' ' && str[len - 1] != ' ')
		{
			if (j == 0)
				token = strtok(str, &delim);
			else
				token = strtok(NULL, &delim);
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
