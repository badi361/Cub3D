/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:47:14 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/24 19:39:37 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	change_map_malloc(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->int_map = malloc(sizeof(int *) * data->mapy_size);
	if (!data->int_map)
		return (1);
	while (j < data->mapy_size)
	{
		i = 0;
		while (data->map[j][i] && data->map[j][i] != '\n')
			i++;
		data->int_map[j] = malloc(sizeof(int) * i);
		if (!data->int_map[j])
			return (1);
		j++;
	}
	return (0);
}

int	change_map(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (++j < data->mapy_size)
	{
		i = 0;
		while (data->map[j][i] && data->map[j][i] != '\n')
		{
			if (data->map[j][i] == '0')
				data->int_map[j][i] = 0;
			else if (data->map[j][i] == '1')
				data->int_map[j][i] = 1;
			else if (data->map[j][i] == 'N' || data->map[j][i] == 'W'
				|| data->map[j][i] == 'E' || data->map[j][i] == 'S')
				data->int_map[j][i] = 0;
			else if (data->map[j][i] == ' ')
				data->int_map[j][i] = 2;
			i++;
		}
		free(data->map[j]);
	}
	free(data->map);
	return (0);
}
