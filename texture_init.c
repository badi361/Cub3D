/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:59:53 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/20 18:10:48 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->data + (y * img->sizeline + x * (img->bpp / 8));
    *(int *)pixel = color;
}




void	start_img(t_data *data)
{
	int	bpp;
	int	sizeline;
	int	endian;

	data->img.image = mlx_new_image(data->mlx, 1920, 1080);
	data->img.data = mlx_get_data_addr(data->img.image, &bpp,
			&sizeline, &endian);
	data->img.bpp = bpp;
	data->img.sizeline = sizeline;
	data->img.endian = endian;
	
}



void	open_textures(t_data *data)
{
	data->north.image = mlx_xpm_file_to_image(data->mlx, "./textures/north.xpm",
			&(data->north.w), &(data->north.h));
	data->south.image = mlx_xpm_file_to_image(data->mlx, "./textures/south.xpm",
			&(data->south.w), &(data->south.h));
	data->west.image = mlx_xpm_file_to_image(data->mlx, "./textures/west.xpm",
			&(data->west.w), &(data->west.h));
	data->east.image = mlx_xpm_file_to_image(data->mlx, "./textures/east.xpm",
			&(data->east.w), &(data->east.h));
	if (!data->north.image || !data->south.image || !data->west.image
		|| !data->east.image)
		printf("Texture Error\n");
	data->north.data = mlx_get_data_addr(data->north.image, &(data->north.bpp),
			&(data->north.sizeline), &(data->north.endian));
	data->south.data = mlx_get_data_addr(data->south.image, &(data->south.bpp),
			&(data->south.sizeline), &(data->south.endian));
	data->west.data = mlx_get_data_addr(data->west.image, &(data->west.bpp),
			&(data->west.sizeline), &(data->west.endian));
	data->east.data = mlx_get_data_addr(data->east.image, &(data->east.bpp),
			&(data->east.sizeline), &(data->east.endian));
}