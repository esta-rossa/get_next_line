#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int c, char **v)
{
	int fd;
	int rt;
	char *line;

	rt = 1;
	fd = open(v[1], O_RDONLY);
	while (rt == 1)
	{
		line = NULL;
		rt = get_next_line(fd, &line);
		printf("%d|%s|\n", rt, line);
		free(line);
	}
	return (0);
}
