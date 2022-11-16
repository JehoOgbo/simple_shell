#include "header.h"

/**
 * build_list - builds a list from the path directories
 * @environ: local environment of the shell
 *
 * Return: pointer to the first node of the list
 */
list_t *build_list(char **environ)
{
	int i = 0;
	char *str, delim = ':', delim1 = '=', *token, *str1, *saveptr, *save;
	list_t *head = NULL;

	while (*(environ + i) != NULL)
	{
		if (strncmp("PATH", *(environ + i), 4) == 0)
			break;
		i++;
	}
	str = strdup(*(environ + i));
	for (i = 0; ; i++)
	{
		if (i == 0)
			token = strtok_r(str, &delim1, &save);
		else
			token = strtok_r(NULL, &delim1, &save);
		if (token == NULL)
			break;
		if (i != 0)
			str1 = token;
	}
	/*free(str);*/
	for (i = 0; ; i++)
	{
		if (i == 0)
			token = strtok_r(str1, &delim, &saveptr);
		else
			token = strtok_r(NULL, &delim, &saveptr);
		if (token == NULL)
			break;
		add_node_end(&head, token);
	}
	free(str);
	/*free(str1);*/
	return (head);
}
