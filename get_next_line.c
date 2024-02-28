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

#include "get_next_line.h"

char *ft_newline(char  *buf)
{
    int i;
    char *buf1;

    i = 0;
    if (!buf)
        return (NULL);
    while(buf[i] != '\n' && buf[i])
        i++;
    buf1 = (char *)malloc(sizeof(char) * (i + 2));
    i = 0;
    while(buf[i] != '\n' && buf[i])
    {
        buf1[i] = buf[i];
        i++;
    }
    while (buf[i] == '\n' && buf[i])
    {
        buf1[i] = '\n';
        i++;
    }
    buf1[i] = '\0';
    return(buf1);
}

char *ft_removeline(char *buffer)
{
    char *str;
    char *u;
    int i;
    int n;

    i = 0;
    n = 0;
    while(buffer[i] != '\n' && buffer[i])
        i++;
    i++;
    str = (char *)malloc(ft_strlen(buffer) - i + 1);
    if (!str)
        return(NULL);
    while(buffer[i])
    {
        str[n] = buffer[i];
        n++;
        i++;
    }
    u = str;
    u[n] = '\0';
    free(str);
    str = NULL;
    return(u);
}

char *ft_readtext(int fd, char *buffer)
{
    char *str;
    int read_char;

    read_char = 1;
    while(read_char > 0)
    {
        str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if(!str)
        {
            free(str);
            return(NULL);
        }
        // printf("BEFORE_BEFORE:'%s'\n", buffer);
        read_char = read(fd, str, BUFFER_SIZE);
        if (read_char == -1)
        {
            free(str);
            free(buffer);
            return(NULL);
        }
        str[read_char] = '\0';
        // printf("before: '%s' before:'%s'\n", buffer, str);
        buffer = ft_strjoin(buffer, str);
        // printf("after:'%s'\n", buffer);
        if (ft_strchr(buffer, '\n'))
			break ;
    }
    free(str);
    return(buffer);
}

char *get_next_line(int fd)
{
    char *buf;
    static char *buffer;

    if(fd < 0 || BUFFER_SIZE < 1 || read(fd, 0 , 0) < 0)
        return(NULL);
    for (int i = 0; i < 3; i++)
        write(1, buffer + i, 1);
    buffer = ft_readtext(fd, buffer);

    if(!buffer)
	{
		buffer = malloc(1);
		buffer[0] = '\0';
        return(NULL);
	}
    buf = ft_newline(buffer);
    buffer = ft_removeline(buffer);
    return(buf);
}



int main()
{
   
    int fd;
    int i = 0;
    //char *g = "";
    fd = open("test.txt", O_RDONLY);

    while (i < 5)
    {
        get_next_line(fd);
        printf("\n=================\n");
        // printf("%s", get_next_line(fd));
        i++;
    }
    
    //printf("%s", ft_readtext(fd, g));
    
    // printf("%s\n", ft_removeline("aaaa\naaa\ns"));

    // printf("%s", ft_newline("aaaa\naaa\ns"));

    return(0);
}
