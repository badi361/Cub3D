/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:50:03 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/24 20:02:02 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data-> plane_x;
	data->dir_x = data-> dir_x * cos(-1 * (data->rot_speed))
		- data->dir_y * sin(-1 * (data->rot_speed));
	data->dir_y = old_dir_x * sin(-1 * (data->rot_speed))
		+ data-> dir_y * cos(-1 * (data->rot_speed));
	data->plane_x = data->plane_x * cos(-1 * (data->rot_speed))
		- data -> plane_y * sin(-1 *(data->rot_speed));
	data->plane_y = old_plane_x * sin(-1 * (data->rot_speed))
		+ data-> plane_y * cos(-1 * (data->rot_speed));
}

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	data->dir_x = data->dir_x * cos(data-> rot_speed) - data->dir_y
		* sin(data->rot_speed);
	data->dir_y = old_dir_x * sin(data->rot_speed) + data->dir_y
		* cos(data->rot_speed);
	data->plane_x = data-> plane_x * cos(data->rot_speed) - data->plane_y
		* sin(data->rot_speed);
	data->plane_y = old_plane_x * sin(data->rot_speed) + data->plane_y
		* cos(data->rot_speed);
}

void	player_move(t_data *data)
{
	if (data->move[0] == 1)
		move_forward(data);
	else if (data->move[1] == 1)
		move_back(data);
	if (data->move[2] == 1)
		move_left(data);
	else if (data->move[3] == 1)
		move_right(data);
	if (data->move[4] == 1)
		rotate_left(data);
	else if (data->move[5] == 1)
		rotate_right(data);
}

void	fill_player_dir(t_data *data, double x, double y)
{
	data->dir_x = x;
	data->dir_x = y;
	if (x < 0.0)
		data->plane_y = -0.66;
	else if (x > 0.0)
		data->plane_y = 0.66;
	else
		data->plane_y = 0;
	if (y < 0.0)
		data->plane_x = 0.66;
	else if (y > 0.0)
		data->plane_x = -0.66;
	else
		data->plane_x = 0;
}
