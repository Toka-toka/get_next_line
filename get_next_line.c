# include "get_next_line.h"

int	join_call(char **line, char *buff, int *start)
{
	int sym_index;

	sym_index = strchr_int(buff, '\n');
	if (sym_index != -1)
		buff[sym_index] = '\0';
	*line = strjoin_free(*line, buff);
	if (*line == NULL)
		return (-1);
	if (sym_index == -1)
		return(2);
	*start += (sym_index + 1);
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
			status = read_call(fd, &buff);
		if (status > 0)
			status = join_call(line, buff + start, &start);
		if (status != 1 || start == BUFFER_SIZE)
		{
			start = 0;
			free(buff);
		}
	}
	return(status);
}