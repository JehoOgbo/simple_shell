#include "header.h"

int main(void)
{
	char str[] = "PWD";
	char *var;

	var = _getenv(str);
	if (var == NULL)
		return (-1);
	printf("%s\n", var);

	return (0);
}
