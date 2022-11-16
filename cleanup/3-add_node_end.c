#include "header.h"	/* Header file already includes other needed headers */

/**
 * add_node_end - adds a node at the end of the list
 * @head: pointer to pointer to the first element of the array
 * @str: string to be added as part of the node
 *
 * Return: address of the new element or NULL if it fails
 */
list_t *add_node_end(list_t **head, const char *str)
{
	/*size_t len;*/
	list_t *ptr, *iterate;

	ptr = malloc(sizeof(list_t));
	if (ptr == NULL)
		return (NULL);

	ptr->str = strdup(str);	/* copy new the string literal */

	/*for (len = 0; str[len]; len++);*/

	/*ptr->len = len;*/
	ptr->next = NULL;
	/* get the last element of the list and set its pointer to new node */
	iterate = *head;
	/* set iterate to value of 1st node */
	if (iterate == NULL)
		*head = ptr;
	else
	{
		while (iterate->next != NULL)
		{
			iterate = iterate->next;
		}
		iterate->next = ptr;	/* setting pointer to new node */
	}

	return (*head);	/* return address of new element */
}
