/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:10:07 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/29 16:18:54 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_init(t_data *data)
{
	data->move_speed = 0.25;
	data->rot_speed = 0.1;
	data->floorc = create_trgb(0, data->floor.r, data->floor.g, data->floor.b);
	data->skyc = create_trgb(0, data->sky.r, data->sky.g, data->sky.b);
}

void	data_init(t_data *data)
{
	data -> mapy_size = 0;
	data -> cub_size = 0;
	data -> player_size = 0;
	data -> zero_size = 0;
	data -> map = NULL;
	data -> image_path = NULL;
	data ->north.path = NULL;
	data ->east.path = NULL;
	data ->south.path = NULL;
	data ->west.path = NULL;
	data ->north.image = NULL;
	data ->west.image = NULL;
	data ->east.image = NULL;
	data ->south.image = NULL;
	data->floor.r = 0;
	data->floor.g = 0;
	data->floor.b = 0;
	data->sky.r = 0;
	data->sky.g = 0;
	data->sky.b = 0;
	data->arg_count = 0;
	data->flager = 0;
	data->so_flag = 0;
	data->no_flag = 0;
}
