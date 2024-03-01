/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <kgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:59:52 by kgalstya          #+#    #+#             */
/*   Updated: 2024/03/01 21:47:48 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int ft_strlen (char *str)
{
    int i;
    
    i = 0;
    while(str[i] != '\0')
        i++;
    return(i);
}

int ft_strchr(char *s, char c)
{
    while (*s)
    {
        if (*s == c)
            return(1);
        s++;
    }
    if (c == '\0')
        return(1);
    return(0);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *res;
    int     i;
    int     j;
    
    if (!s1 || !s2)
        return(NULL);
    res = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
    if (!res)
        return(NULL);
    i = 0;
    j = 0;
    while (s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        res[i] = s2[j];
        i++;
        j++;
    }
    res[i] = '\0';
    return(res);
}

char    *ft_strjoin_free(char *buffer, char *str)
{
    char *res;

    if (!buffer)
    {
        buffer = malloc(1);
        if(!buffer)
            return(NULL);
        buffer[0] = '\0';
    }
    res = ft_strjoin(buffer, str);
    free(buffer);
    return(res);
}