/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:50:03 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/21 15:54:04 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void rotate_right(t_data *data)
{
	double oldDirX = data->dirX;
	data->dirX = data-> dirX * cos(-1 * (data->rotSpeed)) - data->dirY * sin(-1 * (data->rotSpeed));
	data->  dirY = oldDirX * sin(-1 * (data->rotSpeed)) + data-> dirY * cos(-1 * (data->rotSpeed));
	double oldPlaneX = data-> planeX;
	data-> planeX = data->planeX * cos(-1 * (data->rotSpeed)) - data -> planeY * sin(-1 *(data->rotSpeed));
	data->planeY = oldPlaneX * sin(-1 * (data->rotSpeed)) + data-> planeY * cos(-1 * (data->rotSpeed));
}

void rotate_left(t_data *data)
{
	double oldDirX = data-> dirX;
	data->dirX = data->dirX * cos(data-> rotSpeed) - data->dirY * sin(data->rotSpeed);
	data->dirY = oldDirX * sin(data->rotSpeed) + data->dirY * cos(data->rotSpeed);
	double oldPlaneX = data->planeX;
	data-> planeX = data-> planeX * cos(data->rotSpeed) - data->planeY * sin(data->rotSpeed);
	data-> planeY = oldPlaneX * sin(data->rotSpeed) + data->planeY * cos(data->rotSpeed);
}

void player_move(t_data *data)
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