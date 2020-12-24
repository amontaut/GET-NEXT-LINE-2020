#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "RENDU-GNL/get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	int ret;
	int line;
	char *buff;

	line = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &buff)) > 0)
		{
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
			free(buff);
		}
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		free(buff);
	}
	else
	{
		fd = 0;
		printf("no file to read");
		ret = -1;
	}
	if (ret == -1)
		printf("\nError\n");
	else if (ret == 0)
		printf("\nEnd of file\n");
	close(fd);
	return (0);
}
