#include "header.h"

int main(void)
{
	list_t *header;

	header = builde_list();
	while (header)
	{
		printf("%s\n", header->str);
		header = header->next;
	}
	return (0);
}
