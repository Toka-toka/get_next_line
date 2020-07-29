# include "get_next_line.h"
# include <stdio.h>

int	join_call(char **line, char **buff, int *start)
{
	int sym_plase;

	sym_plase = strchr_int(*buff + *start, '\n');
	if (sym_plase != -1)
		buff[0][sym_plase + *start] = '\0';
	*line = strjoin_free(*line, *buff + *start);
	if (*line == NULL)
		return (-1);
	if (sym_plase == -1)
	{
		*start = 0;
		return(2);
	}
	*start += (sym_plase + 1);
	return(1);
}

int	read_call(int fd, char **buff)
{
	int status;

	if (!(*buff = malloc((BUFFER_SIZE +1) * sizeof(char))))
		return(-1);
	status = read(fd, *buff, BUFFER_SIZE);
	buff[0][status] = '\0';
	return(status);
}

int	get_next_line(int fd, char **line)
{
	static char *buff;
	static int	start;
	int			status;

	status = 2;
	if (line == NULL || fd < 0 || BUFFER_SIZE < 1)
		return(-1);
	*line = malloc(sizeof(char) * 1);
	*line[0] = '\0';
	while (status == 2)
	{
		if(start == 0)
		{
			status = read_call(fd, &buff);
		}
		if (status > 0)
			status = join_call(line, &buff, &start);
		if (status != 1)
			free(buff);
	}
	return(status);
}