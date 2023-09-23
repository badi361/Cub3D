/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:10:07 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/23 18:03:42 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void start_init(t_data *data)
{
	data->north.w = 64;
	data->north.h = 64;

	data->east.w = 64;
	data->east.h = 64;

	data->south.w = 64;
	data->south.h = 64;

	data->gun.w = 0;
	data->gun.h = 0;

	data->west.w = 64;
	data->west.h = 64;
	data-> moveSpeed = 0.01;
	data-> rotSpeed = 0.1;
	data-> floorc = create_trgb(0, data->floor.r, data->floor.g, data->floor.b);
	data-> skyc = create_trgb(0, data->sky.r, data->sky.g, data->sky.b);
}

void data_init(t_data *data)
{
	data -> mapy_size = 0;
	data -> cub_size = 0;
	data -> player_size = 0;
	data -> zero_size = 0;
	data-> map = NULL;
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

}