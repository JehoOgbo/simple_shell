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
	int len_dir, len_file;

	len_dir = strlen(directory);
	len_file = strlen(directory);
	str1 = malloc(sizeof(char) * (len_dir + len_file + 2));
	str1 = strcpy(str1, directory);
	strcat(str1, "/");
	strcat(str1, file);
	if (stat(str1, &buffer) == 0)
		return (str1);
	free(str1);
	return (NULL);
}
