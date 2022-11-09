#include "header.h"

extern char **environ;
/**
 * list_build - builds a linked list of the path directories
 *
 * Return: pointer to the first node of the list
 */
list_t *list_build(list_t **header)
{
	int i = 0;
	list_t *new, *old = *header;
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
			break;
		if (i != 0)
		{
			new = malloc(sizeof(list_t));
			new->str = token;
			new->next = NULL;
			if (*header == NULL)
				old = new;
			else
			{
				while (old->next != NULL)
				{
					old = old->next;
				}
				old->next = new;
			}
		}
	}
	return (*header);

}
