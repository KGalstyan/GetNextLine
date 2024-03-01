/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/02/23 01:05:52 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 01:05:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int	ft_strchr(char *s, char c);
int	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t nelem, size_t elsize);
char	*ft_removeline(char *buffer);
char	*ft_readtext(int fd, char *buffer);
char	*ft_newline(char *buf);
char    *ft_strjoin_free(char *buffer, char *str);

#endif