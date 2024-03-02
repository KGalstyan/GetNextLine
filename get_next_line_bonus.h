/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <kgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:00:21 by kgalstya          #+#    #+#             */
/*   Updated: 2024/03/02 10:27:05 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
int		ft_strchr(char *str, char c);
char	*ft_strjoin_free(char *buffer, char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_readtext(int fd, char *buffer);
char	*ft_removeline(char *buffer);
char	*ft_newline(char *buf);

#endif