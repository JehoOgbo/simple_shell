#include <stdio.h>

/**
 * main - prints input from the user
 *
 * Return: 0
 */
int main(void)
{
	char *buffer;
	size_t n = 0;

	printf("$ ");
	if (getline(&buffer, &n, stdin) == -1)
		return (-1);
	printf("%s", buffer);
	return (0);
}
