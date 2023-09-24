/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:47:15 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/24 21:50:40 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin3(char const *s1, char const *s2)
{
	char	*str;
	size_t	k;
	size_t	i;

	k = 0;
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s1 != NULL)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	while (s2[k])
		str[i++] = s2[k++];
	str[i] = '\0';
	return (str);
}

void	ft_get_map_helper(t_data *data)
{
	int		i;
	int		j;
	char	*k;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		k = malloc(sizeof(char) * ft_strlen(data->map[i]) + 2);
		while (data->map[i][j])
		{
			k[j] = data->map[i][j];
			j++;
		}
		k[j] = '\n';
		j++;
		k[j] = '\0';
		free(data->map[i]);
		data->map[i] = ft_strdup(k);
		i++;
	}
}
