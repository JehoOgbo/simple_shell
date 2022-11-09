#include "header.h"

int main(void)
{
	if (_unsetenv("NEW") == -1)
		printf("It didn't work\n");
	return (0);
}
