#include "header.h"

/**
 * free_array - frees an array
 * @array: array to be freed
 *
 * Return: void
 */
void free_array(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
}
