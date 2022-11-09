#include "header.h"

int main(void)
{
	int ck;

	ck = setenv("NAME", "I_set_this", 0);
	if (ck == 0)
		return (0);
	printf("Bad");
	return (-1);
}
