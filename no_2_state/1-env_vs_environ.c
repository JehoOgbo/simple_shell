#include "header.h"

extern char **environ;
/**
 * main - prints the address of global variable env and 3rd parameter of main
 * @ac: argument count
 * @av: argument vector
 * @env: environment variables
 *
 * Return: 0 always success
 */
int main(__attribute__((unused))int ac,__attribute__((unused))char **av, char **env)
{
	printf("Address of environ: %p\n", (void *)environ);
	printf("Address of env: %p\n", (void *)env);
	return (0);
}
