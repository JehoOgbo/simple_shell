#include "header.h"

int main(void)
{
	char *buffer;

	_getline(&buffer);
	printf("%s\n", buffer);
	return (0);
}
