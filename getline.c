#include "header.h"

/**
 * _getline - reads a line from stdin until a newline character is found
 * @buff: address of the buffer to which read information is to be stored
 * @fd: file descriptor of the file stream to be read from
 *
 * Return: number of characters read
 */
int _getline(char **buff, int fd)
{
	int nchar;
	char buf[2048];

	nchar = 2048;
	/*buff = NULL;*/

	nchar = read(fd, buf, nchar);
	if (nchar == -1)
		return (-1);
	*buff = malloc((nchar + 1) * sizeof(char));
	if (*buff == NULL)
		return (-1);
	memset(*buff, 0, nchar + 1);
	strncpy(*buff, buf, nchar);

	return (nchar);
}
