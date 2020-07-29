#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("WAR.txt", O_RDONLY);
	while ((i = get_next_line(fd, &line)))
	{
//		printf("|%d| %s\n", i, line);
		free(line);
	}
	//free(line);
	//i = get_next_line(42, &line);
	printf("|%d| %s\n", i, line);
	free(line);
//	sleep(1000);
	return (0);
}
