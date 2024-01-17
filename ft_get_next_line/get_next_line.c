/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:35:13 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/24 15:08:58 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*ft_next_line(char *str)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	buff = malloc(sizeof(char) * (ft_strlen2(str) - i + 1));
	i++;
	if (!buff)
		return (NULL);
	j = 0;
	while (str[i])
		buff[j++] = str[i++];
	buff[j] = '\0';
	free(str);
	return (buff);
}

char	*ft_linechecker(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_reader(int fd, char *str)
{
	char	*s;
	int		i;

	s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	i = 1;
	while ((ft_strchr2(str, '\n')) && i != 0)
	{
		i = read(fd, s, BUFFER_SIZE);
		if (i == -1)
		{
			free(s);
			return (0);
		}
		s[i] = '\0';
		str = ft_strjoin2(str, s);
	}
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_reader(fd, str);
	if (!str)
		return (0);
	result = ft_linechecker(str);
	str = ft_next_line(str);
	return (result);
}
