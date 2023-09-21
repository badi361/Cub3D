/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:35:04 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/21 16:03:40 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void put_vertical(t_data *data, int x, int start, int end, int color)
{

	while (start < end)
	{
		img_pix_put(&data->img, x, start, color);
		start++;
	}
	
}

int create_game(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	int a = 1;
		for(int x = 0; x < screenWidth; x++)
		{
			//calculate ray position and direction
			double cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
			double rayDirX = data->dirX + data->planeX * cameraX;
			double rayDirY = data->dirY + data->planeY * cameraX;

			//mapin hangi karesinde olduğumuz
      		int mapX = (int)data->posX;
     		int mapY = (int)data->posY;
			  //ilk x ve y ye dokunması için gereken mesafe
			double sideDistX;
      		double sideDistY;

			  //x de ve y de 1 adım gitmek için gereken mesafe
			double deltaDistX, deltaDistY, perpWallDist;

			if (rayDirX == 0) {
				deltaDistX = 1e30;
			} else {
				deltaDistX = fabs(1 / rayDirX);
			}

			if (rayDirY == 0) {
				deltaDistY = 1e30;
			} else {
				deltaDistY = fabs(1 / rayDirY);
			}
			//what direction to step in x or y-direction (either +1 or -1)
			int stepX;
			int stepY;

			int hit = 0; //was there a wall hit?
			int side; //was a NS or a EW wall hit?

					if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (data->posX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - data->posX) * deltaDistX;
			}
			if (rayDirY < 0)
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
				side = 0;
				}
				else
				{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
				}
				//Check if ray has hit a wall
				if (worldMap[mapX][mapY] > 0) hit = 1;
			}
			if(side == 0)
				perpWallDist = (sideDistX - deltaDistX);
			else
				perpWallDist = (sideDistY - deltaDistY);

			int lineHeight = (int)(screenHeight / perpWallDist);

			int drawStart = -lineHeight / 2 + screenHeight / 2;
			if(drawStart < 0)
				drawStart = 0;
			int drawEnd = lineHeight / 2 + screenHeight / 2;
			if(drawEnd >= screenHeight)
				drawEnd = screenHeight - 1;

			int color = ft_create_trgb(0,255,255,0);
			
			//give x and y sides different brightness
			if(side == 1) {color = color / 2;}

			//draw the pixels of the stripe as a vertical line
			put_vertical(data, x, drawStart, drawEnd, color);
		}
		return 0;
}


int	ft_game_loop(t_data *data)
{
	create_background(data);
	create_game(data);
	player_move(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.image, 0, 0);
	
	return 0;
}
 
void start_init(t_data *data)
{
	data->north.w = 64;
	data->north.h = 64;

	data->east.w = 64;
	data->east.h = 64;

	data->south.w = 64;
	data->south.h = 64;

	data->west.w = 64;
	data->west.h = 64;

}



int main(void)
{	t_data *data = malloc(sizeof(t_data));
	data-> moveSpeed = 0.25;
	data-> rotSpeed = 0.1;
	data-> posX = 15;
	data-> posY = 4;  //x and y start position
	data -> dirX = -1;
	data -> dirY = 0; //initial direction vector
	data -> planeX = 0;
	data-> planeY = 0.66; //the 2d raycaster version of camera plane

	data-> floorc = ft_create_trgb(0,90,90,90);
	data-> skyc = ft_create_trgb (0,173,216,240);
	
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, screenWidth, screenHeight, "Raycaster");
	start_init(data);
	start_img(data);
	open_textures(data);
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 3, 0, key_release, data);
	mlx_loop_hook(data->mlx, &ft_game_loop, data);
	mlx_loop(data->mlx);

	//mlx_destroy_window(data->mlx, data->win);
	return 0;
}



