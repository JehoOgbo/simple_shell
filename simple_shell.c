#include <stdio.h>
#include "header.h"

/**
 * main - prints input from the user
 * @ac: argument count
 * @av: argument vector
 * @env: environment variables
 *
 * Return: 0
 */
int main(__attribute__((unused)) int ac, char **av, char **env)
{
	char *buffer;
	size_t n = 0;
	int i = 0, err = 0;
	char **arr;
	list_t *head = build_list(env);

	printf("#cisfun$ ");
	while ((i = getdelim(&buffer, &n, 10, stdin)) != -1)
	{
		arr = split_string(buffer);
		if (arr == NULL)
		{
			printf("#cisfun$ ");
			continue;
		}
		if (strcmp(arr[0], "env") == 0 && !(arr[1]))
			_printenv(env);
		else if (strcmp(arr[0], "setenv") == 0)
			err = _setenv(arr[1], arr[2], env, arr[3]);
		else if (strcmp(arr[0], "unsetenv") == 0)
			err = _unsetenv(arr[1], env, arr[2]);
		else if (strcmp(arr[0], "cd") == 0)
			err = _cd(arr[1]/*, env*/, arr[2]);
		else if (strcmp(arr[0], "exit") == 0)
		{
			if (arr[1] != NULL)
				err = atoi(arr[1]);
			free_array(arr);
			free_list(head);
			exit(err);
		}
		else
			err = get_operator(arr, env, av[0], head);
		if (i == -1)/* || i == EOF)*/
			return (-1);
		printf("#cisfun$ ");
		free_array(arr);
	}
	return (0);
}
