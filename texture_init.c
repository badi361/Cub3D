/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:57:21 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/16 19:37:39 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void create_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	int trgb = ft_create_trgb(0, data->floor.r, data->floor.g, data -> floor.b);
	int trgb2 = ft_create_trgb(0, data->sky.r, data->sky.g, data -> sky.b);
	while (j < HEIGHT / 2)
	{
		i = 0;
		while (i < WIDTH)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_window, i , j, trgb2);
			i++;
		}
		j++;
	}
	
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_window, i , j, trgb);
			i++;
		}
		j++;
	}
}

void	init_textures(t_data *data)
{
	int i = 64;
	data->north.image = mlx_xpm_file_to_image(data->mlx_ptr, data->north.path,
			&i, &i);
	data->south.image = mlx_xpm_file_to_image(data->mlx_ptr, data->south.path,
			&i, &i);
	data->west.image = mlx_xpm_file_to_image(data->mlx_ptr, data->west.path,
			&i, &i);
	data->east.image = mlx_xpm_file_to_image(data->mlx_ptr, data->east.path,
			&i, &i);
	if (!data->north.image || !data->south.image || !data->west.image
		|| !data->east.image)
		printf("Texture Error\n");
}


void create_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->north.image, 50, 50);
}