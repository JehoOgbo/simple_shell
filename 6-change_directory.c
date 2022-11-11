#include "header.h"

/**
 * _cd - changes the current working directory
 * @directory: new directory to be changed to
 * @format: should be null. prevents excess arguments
 *
 * Return: 0 on success -1 on failure
 */
int _cd(char *directory, char *format)
{
	struct stat buff;
	/*char *buffer;*/
	size_t size = 100;
	char *buf = malloc(size);

	if (stat(directory, &buff) == -1)
	{
		perror("cd");
		return (-1);
	}
	if (format)
		fprintf(stderr, "Too many arguments\n");
	if (!(S_ISDIR(buff.st_mode)))
	{
		/* Handle error */
		printf("This is not a directory\n");
		return (-1);
	}
	if (chdir(directory))
	{
		printf("Disallowed access");
		return (-1);
	}
	getcwd(buf, size);
	if (buf == NULL)
	{
		size = 200;
		buf = realloc(buf, size);
		getcwd(buf, size);
	}
	return (0);
}
