#include <stdio.h>
#include  <unistd.h>
#include "get_next_line.h"

int main()
{
	int fd;
	char *line;
	int i;

	if((fd=open("file", O_RDONLY))==-1)
	{
		printf("Cannot open file.\n");
		return (-1);
	}
	while ((i = get_next_line(fd, &line)))
	{
		printf("i = %d %s\n", i, line);
		free(line);
	}
	printf("i = %d %s\n", i, line);
	free(line);
	return 0;
}
