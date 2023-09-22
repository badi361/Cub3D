/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:07:11 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/22 20:27:24 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	calc_texture_pixel_color(t_data *data)
{
	int	color;

	if (data->y < data->drawStart)
		img_pix_put(&data->img, data->x, data->y, data->skyc);
	else if (data->y >= data->drawStart && data->y <= data->drawEnd)
	{
		data->texY = (int)data->texPos & (64 - 1);
		data->texPos += data->step;
		if (data->side == 0 && data->rayDirX > 0)
			color = get_pixel_in_tex(data->north, data->texX, data->texY);
		else if (data->side == 0 && data->rayDirX < 0)
			color = get_pixel_in_tex(data->south, data->texX, data->texY);
		else if (data->side == 1 && data->rayDirY > 0)
			color = get_pixel_in_tex(data->west, data->texX, data->texY);
		else if (data->side == 1 && data->rayDirY < 0)
			color = get_pixel_in_tex(data->east, data->texX, data->texY);
		img_pix_put(&data->img, data->x, data->y, color);
	}
	else
		img_pix_put(&data->img, data->x, data->y, data->floorc);
}


void	calc_wall_x(t_data *data)
{
	data->drawStart = -data->lineHeight / 2 + screenHeight / 2;
	if (data->drawStart < 0)
		data->drawStart = 0;
	data->drawEnd = data->lineHeight / 2 + screenHeight / 2;
	if (data->drawEnd >= screenHeight)
		data->drawEnd = screenHeight - 1;
	if (data->side == 0)
		data->wallX = data->posY + data->perpWallDist * data->rayDirY;
	else
		data->wallX = data->posX + data->perpWallDist * data->rayDirX;
	data->wallX -= floor(data->wallX);
}





int ray_casting(t_data *data)
{
	data -> x = -1;
		while(data->x++ < screenWidth)
		{
			//calculate ray position and direction
			double cameraX = 2 * data->x / (double)screenWidth - 1; //x-coordinate in camera space
			data->rayDirX = data->dirX + data->planeX * cameraX;
			data->rayDirY = data->dirY + data->planeY * cameraX;

			//mapin hangi karesinde olduğumuz
      		int mapX = (int)data->posX;
     		int mapY = (int)data->posY;
			  //ilk x ve y ye dokunması için gereken mesafe
			double sideDistX;
      		double sideDistY;

			  //x de ve y de 1 adım gitmek için gereken mesafe
			double deltaDistX, deltaDistY;

			if (data->rayDirX == 0) {
				deltaDistX = 1e30;
			} else {
				deltaDistX = fabs(1 / data->rayDirX);
			}

			if (data->rayDirY == 0) {
				deltaDistY = 1e30;
			} else {
				deltaDistY = fabs(1 / data->rayDirY);
			}
			//what direction to step in x or y-direction (either +1 or -1)
			int stepX;
			int stepY;

			int hit = 0; //was there a wall hit?
			 //was a NS or a EW wall hit?

					if (data->rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (data->posX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - data->posX) * deltaDistX;
			}
			if (data->rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (data->posY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - data->posY) * deltaDistY;
			}

			while (hit == 0)
			{
				//jump to next map square, either in x-direction, or in y-direction
				if (sideDistX < sideDistY)
				{
				sideDistX += deltaDistX;
				mapX += stepX;
				data->side = 0;
				}
				else
				{
				sideDistY += deltaDistY;
				mapY += stepY;
				data->side = 1;
				}
				//Check if ray has hit a wall
				if (data->worldMap[mapX][mapY] > 0) 
					hit = 1;
			}
			if(data->side == 0)
				data->perpWallDist = (sideDistX - deltaDistX);
			else
				data->perpWallDist = (sideDistY - deltaDistY);

			data->lineHeight = (int)(screenHeight / data->perpWallDist);

			data-> drawStart = -data->lineHeight / 2 + screenHeight / 2;
			if(data->drawStart < 0)
				data->drawStart = 0;
			data-> drawEnd = data->lineHeight / 2 + screenHeight / 2;
			if(data->drawEnd >= screenHeight)
				data->drawEnd = screenHeight - 1;

	
			calc_wall_x(data);
			data-> texX = (int)data->wallX * (double)64;
			data->texX = (int)(data->wallX * (double)64);
			data->step = 1.0 * 64 / data->lineHeight;
			data-> texPos = (data->drawStart - screenHeight / 2 + data->lineHeight / 2)
			* data->step;

			data->y = data->drawStart;
			 data->y = 1;
			while (data->y < screenHeight)
			{
				calc_texture_pixel_color(data);
				data->y++;
			}
		}
		return 0;
}