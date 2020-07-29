# include "get_next_line.h"

int		strchr_int(const char *s, int c)
{
	char	*str;
	char	symbol;
	int	i;

	i = 0;
	symbol = (char)c;
	str = (char*)s;
	while (str[i] != '\0')
	{
		if (str[i] == symbol)
			return (i);
		i++;
	}
	return (c == '\0' ? i : -1);
}

char		*strjoin_free(char *s1, char const *s2)
{
	char	*s3;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (s3 == NULL)
		return (NULL);
	ft_memcpy(s3, s1, len_s1);
	ft_memcpy(s3 + len_s1, s2, len_s2);
	free(s1);
	s3[len_s1 + len_s2] = '\0';
	return (s3);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *dest_point;
	unsigned char *src_point;

	dest_point = (unsigned char*)dest;
	src_point = (unsigned char*)src;
	if (dest_point == NULL && src_point == NULL)
		return (dest);
	while (n > 0)
	{
		*dest_point++ = *src_point++;
		n--;
	}
	return (dest);
}
