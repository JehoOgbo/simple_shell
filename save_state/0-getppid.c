#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * main - prints pid of parent process
 *
 * Return: 0
 */
int main(void)
{
	pid_t ppid;

	ppid = getppid();
	printf("%d\n", ppid);

	return (0);
}
