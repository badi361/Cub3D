/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:47:14 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/23 18:23:32 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void change_map(t_data *data)
{
	int i = 0;
	int j = 0;
	data->worldMap = malloc(sizeof(int *) * data->mapy_size);
	while (j < data->mapy_size)
	{
		i = 0;
		while (data->map[j][i] && data->map[j][i] != '\n')
			i++;
		data->worldMap[j] = malloc(sizeof(int) * i);
		j++;
	}
	j = 0;
	while (j < data->mapy_size)
	{
		i = 0;
		while (data->map[j][i] && data->map[j][i] != '\n')
		{
			if (data->map[j][i] == '0')
				data->worldMap[j][i] = 0;
			else if (data->map[j][i] == '1')
				data->worldMap[j][i] = 1;
			else if (data->map[j][i] == 'N' || data->map[j][i] == 'W' || data->map[j][i] == 'E' || data->map[j][i] == 'S')
				data->worldMap[j][i] = 0;
			else if (data->map[j][i] == ' ')
				data->worldMap[j][i] = 2;
			i++;
		}
		free(data->map[j]);
		j++;
	}
	free(data->map);
}