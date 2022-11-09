#include "header.h"

/**
 * open_dir - opens and seaches the directory for the executable
 * @direct: directory name
 * @name: name of the command entered
 *
 * Return: indicator that shows if the directory name was found
 */
int open_dir(char *direct, char *name)
{
	DIR* dir = opendir(direct);

	if (dir == NULL)
	{
		closedir(dir);
		return (-1);
	}

	struct dirent *entity;
	entity = readdir(dir);
	while (entity != NULL)
	{
		if (strcmp(name, entity->d_name) == 0)
		{
			closedir(dir);
			return (0);
		}
		entity = readdir(dir);
	}
	closedir(dir);
	return (1);
}
