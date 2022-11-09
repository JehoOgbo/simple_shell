#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

void get_operator(char *buffer, char **environ)
{
	pid_t pid;
	char *argv[2];
	int len;

	len = strlen(buffer);
	buffer[len - 1] = '\0';
	/*strcpy(argv[0], buffer, NULL};*/
	argv[0] = buffer;
	argv[1] = NULL;
	pid = fork();
	if (pid == -1)
	{
		perror("An error occured");
		exit(EXIT_FAILURE);
	}
	wait(NULL);

	/**for (i = 0; i < 4; i++)
	{
		if (pid == 0)
			break;
		pid = fork();
		if (pid == -1)
		{
			perror("An error occured");
			exit(EXIT_FAILURE);
		}
		wait(NULL);
		}*/

	if (pid == 0)
	{
		execve(argv[0], argv, environ);
	}
}
