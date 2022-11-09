#include "header.h"

/**
 * _getline - gets a line input from the standin
 * @lineptr: pointer to the buffer to be used to store the line
 *
 * Return: number of characters read excluding null bytes
 */
/**int _getline(char **lineptr, char *stream)
{
	int fd;
	ssize_t count_read;
	char buffer[1024];

	fd = open(1, O_RDONLY);
	if (fd == -1)
		return (0);
	count_read = read(fd, buffer, 1024);
	if (count_read == -1)
		return (-1);
	*lineptr = malloc(sizeof(char) * count_read);
	*lineptr = buffer;
	close(fd);
	return (count_read);
}*/
int _getline(char **s)
{
	int c, i;

	for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
		*s[i] = c;
	if (c == '\n')
	{
		*s[i] = c;
		++i;
	}
	*s[i] = '\0';
	return (i);
}
