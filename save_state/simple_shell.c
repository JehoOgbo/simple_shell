#include <stdio.h>
#include "header.h"

extern char **environ;
/**
 * main - prints input from the user
 *
 * Return: 0
 */
int main(void)
{
	char *buffer;
	size_t n = 0;
	int i;

	printf("#cisfun$ ");
	while ((i = getline(&buffer, &n, stdin)) != -1)
	{
		get_operator(buffer, environ);
		/*if (i == -1)*/
		/*return (-1);*/
		/*printf("%s", buffer);*/
		printf("#cisfun$ ");
	}
	return (0);
}
