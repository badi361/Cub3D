/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:41:41 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/23 15:53:55 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void move_forward(t_data *data)
{
	if(data->worldMap[(int)(data->posY)][(int)(data->posX + data->dirX * data->moveSpeed)] == 0) 
		data->posX += data->dirX * data->moveSpeed;
	if(data->worldMap[(int)(data->posY + data->dirY * data->moveSpeed)][(int)(data->posX)] == 0)
		 data->posY += data->dirY * data->moveSpeed;
}

void move_back(t_data *data)
{	
	if(data->worldMap[(int)(data->posY)][(int)(data->posX - data->dirX * data->moveSpeed)] == 0) 
		data->posX -= data->dirX * data->moveSpeed;
	if(data->worldMap[(int)(data->posY - data->dirY * data->moveSpeed)][(int)(data->posX)] == 0)
		data->posY -= data->dirY * data->moveSpeed;
}

void move_right(t_data *data)
{
	
	if(data->worldMap[(int)(data->posY)][(int)(data->posX + data->planeX * data->moveSpeed)] == 0) 
		data->posX += data->planeX * data->moveSpeed;
	if(data->worldMap[(int)(data->posY + data->planeY * data->moveSpeed)][(int)(data->posX)] == 0)
		data->posY += data->planeY * data->moveSpeed;
}

void move_left(t_data *data)
{

	if(data->worldMap[(int)(data->posY)][(int)(data->posX - (data->planeX * data->moveSpeed))] == 0) 
		data->posX -= data->planeX * data->moveSpeed;
	if(data->worldMap[(int)(data->posY - data->planeY * data->moveSpeed)][(int)(data->posX)] == 0)
		data->posY -= data->planeY * data->moveSpeed;
}