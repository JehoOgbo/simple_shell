#include "header.h"

/**
 * check_dir - check if the file can be located from the path
 * @directory: name of directory
 * @file: name of file to be checked
 *
 * Return: NULL or concatenated str
 */
char *check_dir(char *directory, char *file)
{
	struct stat buffer;
	char *str1;

	str1 = strdup(directory);
	strcat(str1, "/");
	strcat(str1, file);
	if (stat(str1, &buffer) == 0)
		return (str1);
	return (NULL);
}
