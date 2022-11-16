#include <stdio.h>
#include "header.h"

/**
 * execute - executes necessary command
 * @buffer: contains the commands that will to be run by the shell
 * @number: controls freeing of possible memory in environment variable
 * @head: pointer to the first element of a linked list
 * @av: name of the shell
 * @env: environment variables of the local environment
 *
 * Return: 0
 */
int execute(char *buffer, char **env, int number, list_t *head, char *av)
{
	char **arr;
	int err = 0;

	arr = split_string(buffer);
	if (arr == NULL)
	{
		printf("#cisfun$ ");
		return (err);
	}
	if (strcmp(arr[0], "env") == 0 && !(arr[1]))
		_printenv(env);
	else if (strcmp(arr[0], "setenv") == 0)
		err = _setenv(arr[1], arr[2], env, arr[3]);
	else if (strcmp(arr[0], "unsetenv") == 0)
		err = _unsetenv(arr[1], env, arr[2], number);
	else if (strcmp(arr[0], "cd") == 0)
		err = _cd(arr[1], arr[2]);
	else if (strcmp(arr[0], "exit") == 0)
		exitr(arr[1], env, buffer, arr, head, err, number);
	else if (strcmp(arr[0], "simple_shell") == 0)
		readfile(arr[1], arr[2], env, head, number, av);
	else
		err = get_operator(arr, env, av, head);
	free_array(arr);

	return (err);
}
