#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

/**
 * get_operator - checks if the file exists and runs the executable
 * @buffer: array of char pointers containing command and arguments
 * @environ: array of char pointers containing environment variables
 * @arg: pointer to the string used to start shell (for error messages)
 * @head: pointer to the first element of a linked list
 *
 * Return: void
 */
int get_operator(char **buffer, char **environ, char *arg, list_t *head)
{
	pid_t pid;
	struct stat buf;
	int checker = 0, status;
	char *str;

	status = stat(buffer[0], &buf);
	if (status != 0)
	{
		while (head)
		{
			str = check_dir(head->str, buffer[0]);
			if (str)
			{
				checker = 1;
				break;
			}
			head = head->next;
		}
	}
	if (status != 0 && checker != 1)
	{
		perror(arg);
		return (-1);
	}
	if (status != 0)
	{
		buffer[0] = strcpy(buffer[0], str);
		free(str);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("An error occured");
		exit(EXIT_FAILURE);
	}
	wait(NULL);

	if (pid == 0)
		execve(buffer[0], buffer, environ);
	return (0);
}
