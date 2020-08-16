/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 22:22:02 by sedric            #+#    #+#             */
/*   Updated: 2020/08/16 18:57:21 by sedric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	int				fd;
	char			*buff;
	int				start;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);
int					strchr_int(const char *s, int c);
char				*strjoin(char *s1, char const *s2);
size_t				ft_strlen(const char *s);
void				*ft_memcpy(void *dest, const void *src, size_t n);

#endif
