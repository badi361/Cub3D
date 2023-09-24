/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:48:19 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/24 21:49:51 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_first_rotate(t_data *data)
{
	if (data->player_r == 'N')
	{
		data->dir_x = 0.0;
		data->dir_y = -1.0;
		data->plane_x = 0.66;
		data->plane_y = 0.0;
	}
	else if (data->player_r == 'S')
	{
		data->dir_x = 0.0;
		data->dir_y = 1.0;
		data->plane_x = -0.66;
		data->plane_y = 0.0;
	}
	player_rotate_helper(data);
}

void	ft_map_check_helper(int i, int j, t_data *data)
{
	data->player_r = data->map[j][i];
	data -> start_player_x = i;
	data -> start_player_y = j;
	data ->pos_x = (double)i + 0.5;
	data -> pos_y = (double)j + 0.5;
	data -> player_size++;
}

void	player_rotate_helper(t_data *data)
{
	if (data->player_r == 'W')
	{
		data->dir_x = -1.0;
		data->dir_y = 0.0;
		data->plane_x = 0.0;
		data->plane_y = -0.66;
	}
	else if (data->player_r == 'E')
	{
		data->dir_x = 1.0;
		data->dir_y = 0.0;
		data->plane_x = 0.0;
		data->plane_y = 0.66;
	}
}
