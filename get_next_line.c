# include "get_next_line.h"
# include <stdio.h>

int	get_next_line(int fd, char **line)
{
	static char *buff;
	char *temp;
	int	sym_plase = 0;
	int	sym_read = 0;
	printf("buff = %s", buff);
	if (line == NULL || fd < 0 || BUFFER_SIZE < 1)
		return(-1);
	if(buff == NULL)
		printf("проверка работает");
	else printf("второй заход");
	buff = malloc((BUFFER_SIZE +1) * sizeof(char));
	free(buff);
//	buff = NULL;
/*	sym_read = read(fd, buff, BUFFER_SIZE);
	sym_plase = ft_strchr(*line, '\n');
	if (sym_plase != -1)
	{
		buff[sym_plase] = '\0';
		sym_plase++;
		temp = ft_substr(buff, sym_plase, sym_read - sym_plase);
	}	
	*line = ft_strdup(buff);
		while ((sym_plase = ft_strchr(*line, '\n')) == -1)
		{
			read(fd, buff, BUFFER_SIZE);
			*line = ft_strjoin(*line, buff);
//			printf("line = %s\n", *line);
		}
//		printf("Sym_read = %d\n", sym_plase);
		return(1);
	}
	else return (0);
//	ft_strlen(buff);
/*	temp = malloc(5 * sizeof(char));
//	char buff[BUFFER_SIZE + 1];
	temp[4] = '\0';
	while (temp[i] != '\0')
	{
		temp[i] = 'A';
		i++;
	}
	*line = temp;*/
	return(1);
}
