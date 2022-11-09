#include <stdio.h>

/**
 * main - prints all command line arguments without using ac
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 always success
 */
int main(__attribute__((unused)) int ac, char **av)
{
	int i = 0;

	while (av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
