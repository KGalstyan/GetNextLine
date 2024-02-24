/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:33:29 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 01:33:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
# define BUFFER_SIZE 50

char *ft_newline(char  *buf)
{
    int i;
    char *buf1;

    i = 0;
    while(buf[i] != '\n' && buf[i])
    i++;
    buf1 = (char *)malloc(sizeof(char) * (i + 2));
    i = 0;
    while(buf[i] != '\n' && buf[i])
    {
        buf1[i] = buf[i];
        i++;
    }
    buf1[i - 1] = '\n';
    buf1[i] = '\0'
    return(buf1);
}

char *ft_removeline(char *str1, char *str2)
{
    int n;

    n = ft_strlen(str1) - 1;
    while(n > 0)
    {
        
    }
}

char *ft_readtext(int fd, char *buffer)
{
    int char_read;
    char *buf;
    char *str;

    char_read = 1;
	while (char_read > 0)
	{
    	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    	if (buffer == NULL)
        	return(NULL);
    	char_read = read(fd, buffer, BUFFER_SIZE);
    	if (char_read < 0)
    	{
        	free (buffer);
        	return(NULL);
    	}
		buffer[char_read] = '\0';
        buf = ft_strjoin(buffer, buf);
		if(ft_strchr(buffer, '\n'));
            break;
	}
    return(buf);
}

char *get_next_line(int fd)
{
    static char *buffer;

}

int main()
{
    int fd;
    fd = open ("test.txt", O_RDONLY);
    char *des = ft_tostr(fd);

    printf ("%s\n", ft_strchr(des, '\n'));
    return(0);
}