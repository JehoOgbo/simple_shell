#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **envp)
{
	pid_t pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int i;

	pid = fork();
	if (pid == -1)
	{
		perror("An error occured");
		exit(EXIT_FAILURE);
	}
	wait(NULL);

	for (i = 0; i < 4; i++)
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
	}

	if (pid == 0)
	{
		execve(argv[0], argv, envp);
	}
	return (0);
}
