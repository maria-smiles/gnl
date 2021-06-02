#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


int main(int argc, char **argv)
{
	char *line;
	int fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Cannot open file.\n");
			return (-1);
		}
	}
	else if (argc == 1)
		fd = 0;
	else
	{
		printf("too many arguments");
		return (-1);
	}

	while (get_next_line(fd, &line))
		printf("%s\n", line);
}


//int main(int argc, char **argv)
//{
//	(void)argv;
//	int fd;
//	char *line;
//	int i;
//
//	line = NULL;
//	printf ("argc = %d\n", argc);
//	if (argc == 2)
//	{
//		fd = open(argv[1], O_RDONLY);
//		if (fd == -1)
//		{
//			printf("Cannot open file.\n");
//			return (-1);
//		}
//
//		while ((i = get_next_line(fd, &line)) != -1)
//		{
//			printf("i = %d %s\n", i, line);
//			free(line);
//		}
//
//		printf("i = %d %s\n", i, line);
//		free(line);
//	}
//	else if (argc == 1)
//	{
//		while ((i = get_next_line(0, &line)) == 1)
//		{
//			printf("i = %d %s\n", i, line);
//			free(line);
//		}
//
//		printf("i = %d %s\n", i, line);
//		free(line);
//	}
//	else
//	{
//		printf("too many arguments");
//		return (-1);
//	}
//
//
//	return (0);
//}
