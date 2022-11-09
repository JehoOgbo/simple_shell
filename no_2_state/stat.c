#include "header.h"

/**
 * main - looks for a file in the current path
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 always success
 */
int main(int ac, char **av)
{
	int i = 1;
	struct stat buffer;

	if (ac < 2)
	{
		printf("Usage: _which filename\n");
		exit(EXIT_FAILURE);
	}
	while (av[i])
	{
		if (stat(av[i], &buffer) == 0)
			printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
