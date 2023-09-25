/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:32:32 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/25 16:34:54 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tex_paths_2(t_data *data)
{
	if (data->north.path)
		free(data->north.path);
	if (data->south.path)
		free(data->south.path);
	if (data->west.path)
		free(data->west.path);
	if (data->east.path)
		free(data->east.path);
	if (data->gun.path)
		free(data->gun.path);
}

void	free_map2(t_data *data)
{
	int	i;

	i = data->mapy_size - 1;
	while (i >= 0)
	{
		free(data->int_map[i]);
		i--;
	}
	free(data->int_map);
}

void	free_game(t_data *data)
{
	free_map2(data);
	free_tex_paths_2(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.image);
	mlx_destroy_image(data->mlx, data->gun.image);
	mlx_destroy_image(data->mlx, data->north.image);
	mlx_destroy_image(data->mlx, data->east.image);
	mlx_destroy_image(data->mlx, data->west.image);
	mlx_destroy_image(data->mlx, data->south.image);
	exit(0);
}
