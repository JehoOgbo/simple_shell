#include <stdio.h>
#include "header.h"
#include <stdlib.h>

/**
 * main - calls other funcs
 *
 * Return: 0
 */
int main(void)
{
	char string[] = "My name is Urom Jehoshaphat and I am a good boy";
	char **arr;
	int i = 0;

	arr = split_string(string);
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}
