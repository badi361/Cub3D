/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:35:20 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/14 17:21:32 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

int		ft_strlen2(const char *s);
char	*ft_strjoin2(char *s1, char *s2);
int		ft_strchr2(char *str, char c);
char	*ft_next_line(char *str);
char	*ft_linechecker(char *str);
char	*ft_reader(int fd, char *str);
char	*get_next_line(int fd);
#endif