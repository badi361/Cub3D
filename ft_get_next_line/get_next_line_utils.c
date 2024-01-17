/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:35:04 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/14 17:21:24 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen2(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*hamper;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	i = 0;
	j = 0;
	if (!s2)
		return (0);
	hamper = (char *)malloc(ft_strlen2(s1) + ft_strlen2(s2) + 1);
	if (!hamper)
		return (0);
	while (s1[i] != '\0')
		hamper[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		hamper[j++] = s2[i++];
	hamper[j] = '\0';
	free (s1);
	return (hamper);
}

int	ft_strchr2(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}
