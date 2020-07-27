#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main()
{
	int i = 0;	
	int fd;
	int return_value;
	char buff[5];

	fd = open("test", O_RDONLY);
	while (i != 10)
	{
		return_value = read(fd, buff, 5);
		i++;
		printf("i = %d read = %d buff = %s\n", i, return_value, buff);
		buff[0] = '\0';
		buff[1] = '\0';
	}
}
