/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:57:21 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/15 20:04:48 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int start_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx_ptr, WIDTH, 
 	HEIGHT, "Cub3D");


	//mlx_hook(data->win_ptr, 17, 0, (void *)ft_exit, data);
	mlx_hook(data->mlx_window, 2, 0, ft_exit, data);
	mlx_loop(data->mlx_ptr);
	mlx_hook(data->mlx_window, 2, 1L << 0, ft_exit, data);
	//mlx_hook(data->mlx_window, 17, 0, (void *)ft_exit, data);
	return (0);
}

int	ft_exit(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		exit(0);
	}
	return (0);
}

