/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 23:51:35 by sedric            #+#    #+#             */
/*   Updated: 2020/08/16 18:53:21 by sedric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

static int		join_call(char **line, char *buff, int *start)
{
	int		sym_index;
	char	*temp;

	temp = *line;
	if ((sym_index = strchr_int(buff, '\n')) == -1)
	{
		if (!(*line = strjoin(*line, buff)))
			return (-1);
		free(temp);
		*start = 0;
		return (2);
	}
	buff[sym_index] = '\0';
	if (!(*line = strjoin(*line, buff)))
		return (-1);
	free(temp);
	*start += sym_index + 1;
	return (1);
}

static int		read_join_call(char **line, int fd, char *buff, int *start)
{
	int		status;

	status = 2;
	*line = malloc(sizeof(char) * 1);
	*line[0] = '\0';
	while (status == 2)
	{
		if (*start == 0)
		{
			if ((status = read(fd, buff, BUFFER_SIZE)) != -1)
				buff[status] = '\0';
		}
		if (status > 0)
			status = join_call(line, buff + *start, start);
	}
	return (status);
}

static	int		free_list(t_list **head, int fd, int status)
{
	t_list	*current;
	t_list	*previous;

	current = *head;
	while (current->fd != fd)
	{
		previous = current;
		current = current->next;
	}
	if (current == *head)
		*head = current->next;
	else
		previous->next = current->next;
	free(current->buff);
	free(current);
	return (status);
}

static t_list	*new_list(int fd)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new->buff = malloc((BUFFER_SIZE + 1) * sizeof(char))))
	{
		free(new);
		return (NULL);
	}
	new->fd = fd;
	new->start = 0;
	new->next = NULL;
	return (new);
}

int				get_next_line(int fd, char **line)
{
	static	t_list	*head;
	t_list			*temp;
	int				status;

	if (line == NULL || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (head == NULL && (head = new_list(fd)) == NULL)
		return (-1);
	temp = head;
	while (temp->fd != fd)
	{
		if (temp->next == NULL && (temp->next = new_list(fd)) == NULL)
			return (-1);
		temp = temp->next;
	}
	status = read_join_call(line, temp->fd, temp->buff, &temp->start);
	return (status == 1 ? 1 : free_list(&head, temp->fd, status));
}
