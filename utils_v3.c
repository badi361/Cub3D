/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:47:15 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/28 16:00:29 by bguzel           ###   ########.fr       */
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
	free((void *)s1);
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
		free(k);
		i++;
	}
}

void	get_map_helper_2(t_data *data, int fd)
{
	data->image_path = get_next_line(fd);
	if (data->image_path == NULL)
		ft_error_msg("INVALID MAP Error");
	while (data->image_path[0] == '\n')
	{
		free(data->image_path);
		data->image_path = get_next_line(fd);
		if (data->image_path == NULL)
			ft_error_msg("INVALID MAP Error");
	}
	last_colomn_ctrl(data, fd);
}

void	last_colomn_ctrl(t_data *data, int fd)
{
	char	*str;

	str = NULL;
	while (data->image_path)
	{
		data->mapy_size++;
		str = ft_strjoin3(str, data->image_path);
		free(data->image_path);
		data->image_path = get_next_line(fd);
		if (data->image_path == NULL)
			break ;
		if (data->image_path[0] == '\n')
			ft_error_msg("Map division Error");
	}
	data->map = ft_split(str, '\n');
	free(str);
	ft_get_map_helper(data);
	close(fd);
}
