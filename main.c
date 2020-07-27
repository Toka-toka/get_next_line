#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int i = 0;	
	int fd;
	int return_value;
	char *line;

	fd = open("test", O_RDONLY);
	while ((return_value = get_next_line(fd, &line)) != 0 && i != 3)
	{
		printf("Return = %d ", return_value);
		printf("line = %s\n", line);
		i++;
	}
	printf("Return = %d ", return_value);
}
