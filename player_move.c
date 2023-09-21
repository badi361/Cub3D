/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:41:41 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/21 15:48:03 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void move_forward(t_data *data)
{
	if(worldMap[(int)(data->posX + data->dirX * data->moveSpeed)][(int)(data->posY)] == 0) 
		data->posX += data->dirX * data->moveSpeed;
	if(worldMap[(int)(data->posX)][(int)(data->posY + data->dirY * data->moveSpeed)] == 0)
		 data->posY += data->dirY * data->moveSpeed;
}

void move_back(t_data *data)
{	
	if(worldMap[(int)(data->posX - data->dirX * data->moveSpeed)][(int)(data->posY)] == 0) 
		data->posX -= data->dirX * data->moveSpeed;
	if(worldMap[(int)(data->posX)][(int)(data->posY - data->dirY * data->moveSpeed)] == 0)
		data->posY -= data->dirY * data->moveSpeed;
}

void move_right(t_data *data)
{
	
	if(worldMap[(int)(data->posX + data->planeX * data->moveSpeed)][(int)(data->posY)] == 0) 
		data->posX += data->planeX * data->moveSpeed;
	if(worldMap[(int)(data->posX)][(int)(data->posY + data->planeY * data->moveSpeed)] == 0)
		data->posY += data->planeY * data->moveSpeed;
}

void move_left(t_data *data)
{

	if(worldMap[(int)(data->posX - (data->planeX * data->moveSpeed))][(int)(data->posY)] == 0) 
		data->posX -= data->planeX * data->moveSpeed;
	if(worldMap[(int)(data->posX)][(int)(data->posY - data->planeY * data->moveSpeed)] == 0)
		data->posY -= data->planeY * data->moveSpeed;
}