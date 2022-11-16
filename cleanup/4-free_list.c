#include "header.h"

/**
 * free_list - frees a list
 * @head: head of the linked list
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *current;

	while ((current = head) != NULL)
	{
		head = head->next;
		free(current->str);
		free(current);
	}
	head = NULL;
}
