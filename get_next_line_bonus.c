/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <kgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:27:11 by kgalstya          #+#    #+#             */
/*   Updated: 2024/03/01 22:47:27 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_newline(char *buf)
{
	int		i;
	char	*buf1;

	i = 0;
	if (!buf)
		return (NULL);
	while (buf[i] != '\n' && buf[i])
		i++;
	buf1 = (char *)malloc(sizeof(char) * (i + 2));
	if (!buf1)
		return (NULL);
	i = 0;
	while (buf[i] != '\n' && buf[i])
	{
		buf1[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n' && buf[i])
	{
		buf1[i] = '\n';
		i++;
	}
	buf1[i] = '\0';
	return (buf1);
}

char	*ft_removeline(char *buffer)
{
	char	*str;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	str = (char *)malloc(ft_strlen(buffer) - i + 1);
	if (!str)
		return (NULL);
	while (buffer[i])
		str[n++] = buffer[i++];
	str[n] = '\0';
	free(buffer);
	return (str);
}

char    *ft_readtext(int fd, char *buffer)
{
    char    *str;
    int     read_char;

    read_char = 1;
    str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!str)
        return(NULL);
    while (read_char > 0)
    {
        read_char = read(fd, str, BUFFER_SIZE);
        if (read_char == -1)
        {
            free(str);
            return(NULL);
        }
        str[read_char] = '\0';
        buffer = ft_strjoin_free(buffer, str);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    free(str);
    return(buffer);
}

char    *get_next_line(int fd)
{
    static char *buffer[OPEN_MAX];
    char        *buf;
    
    if (BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0))
    {
        free(buffer[fd]);
        buffer[fd] = NULL;
        return(NULL);
    }
    buffer[fd] = ft_readtext(fd, buffer[fd]);
    if (!buffer[fd])
        return(NULL);
    buf = ft_newline(buffer[fd]);
    buffer[fd] = ft_removeline(buffer[fd]);
    if (*buf == '\0')
	{
		free(buf);
		free(buffer[fd]);
		buffer[fd] = NULL;
		buf = NULL;
	}
	return (buf);
}