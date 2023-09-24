/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:41:41 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/24 15:02:44 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_data *data)
{
	if (data->int_map[(int)(data->pos_y)]
		[(int)(data->pos_x + data->dir_x * data->move_speed)] == 0)
		data->pos_x += data->dir_x * data->move_speed;
	if (data->int_map[(int)(data->pos_y + data->dir_y * data->move_speed)]
		[(int)(data->pos_x)] == 0)
		data->pos_y += data->dir_y * data->move_speed;
}

void	move_back(t_data *data)
{
	if (data->int_map[(int)(data->pos_y)]
		[(int)(data->pos_x - data->dir_x * data->move_speed)] == 0)
		data->pos_x -= data->dir_x * data->move_speed;
	if (data->int_map[(int)(data->pos_y - data->dir_y * data->move_speed)]
		[(int)(data->pos_x)] == 0)
		data->pos_y -= data->dir_y * data->move_speed;
}

void	move_right(t_data *data)
{
	if (data->int_map[(int)(data->pos_y)]
		[(int)(data->pos_x + data->plane_x * data->move_speed)] == 0)
		data->pos_x += data->plane_x * data->move_speed;
	if (data->int_map[(int)(data->pos_y + data->plane_y * data->move_speed)]
		[(int)(data->pos_x)] == 0)
		data->pos_y += data->plane_y * data->move_speed;
}

void	move_left(t_data *data)
{
	if (data->int_map[(int)(data->pos_y)]
		[(int)(data->pos_x - (data->plane_x * data->move_speed))] == 0)
		data->pos_x -= data->plane_x * data->move_speed;
	if (data->int_map[(int)(data->pos_y - data->plane_y * data->move_speed)]
		[(int)(data->pos_x)] == 0)
		data->pos_y -= data->plane_y * data->move_speed;
}
