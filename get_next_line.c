# include "get_next_line.h"
# include <stdio.h>

int	search_start(char **line, char **buff, int *start)
{
	int sym_plase;

	sym_plase = ft_strchr(*buff + *start, '\n');
	if (sym_plase != -1)
		buff[0][sym_plase + *start] = '\0';
	*line = ft_strjoin(*line, *buff + *start);
	if (*line == NULL)
		return (-1);
	if (sym_plase == -1)
	{
		free(*buff);
		*buff = NULL;
		return(0);
	}
	*start += (sym_plase + 1);
	return(1);
}

int	read_coal(int fd, char **buff)
{
	int status;

	status = 0;
	if (!(*buff = malloc((BUFFER_SIZE +1) * sizeof(char))))
		return(-1);
	status = read(fd, *buff, BUFFER_SIZE);
	if (status > 0)
	{
		buff[0][status] = '\0';
		return(status);
	}
	else if (status == 0)
		return(-2);
	else
	{
		free (*buff);
		return(-1);
	}
}

int	get_next_line(int fd, char **line)
{
	static char *buff;
	static int	start;
	int			status;

	status = 0;
	if (line == NULL || fd < 0 || BUFFER_SIZE < 1)
		return(-1);
	*line = ft_strdup("\0");
	while (status == 0)
	{
		if(buff == NULL)
		{
			start = 0;
			status = read_coal(fd, &buff);
		}
		if (status >= 0)
			status = search_start(line, &buff, &start);
	}
	if (status == -2) // не освободили память при ошибке чтения
	{
		free(buff);
		buff = NULL;
		return(0);
	}
	return(status);
}