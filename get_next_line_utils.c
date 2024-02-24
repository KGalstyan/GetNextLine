/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:33:41 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 01:33:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
# define BUFFER_SIZE 50

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	int		n;
	char	*res;

	if (!s1)
		return (NULL);
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	n = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0')
	{
		res[i] = s2[n];
		n++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int main()
{
    int fd;
    fd = open ("test.txt", O_RDONLY);
    char *des = ft_tostr(fd);

    printf ("%s\n", ft_strchr(des, '\n'));
    return(0);
}