/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:57:21 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/16 19:46:29 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	x_close(int keycode, t_data *data)
{
	(void)data;
	(void)keycode;
	exit(0);
	return (0);
}

int	key_press(int keycode, t_data *data) //13 1 0 2 up down left right
{
	(void)data;
	printf("keycode %d\n", keycode);
	if (keycode == 13)
		data->move[0] = 1;
	else if (keycode == 1)
		data->move[1] = 1;
	else if (keycode == 0)
		data->move[2] = 1;
	else if (keycode == 2)
		data->move[3] = 1;	
	else if (keycode == 123)
		data->move[4] = 1;
	else if (keycode == 124)
		data->move[5] = 1;
	else if (keycode == 53)
		exit(0);
	return (0);
}

int	key_break(int keycode, t_data *data) //13 1 0 2 up down left right
{
	(void)data;
	printf("keycode %d\n", keycode);
	if (keycode == 13)
		data->move[0] = 0;
	else if (keycode == 1)
		data->move[1] = 0;
	else if (keycode == 0)
		data->move[2] = 0;
	else if (keycode == 2)
		data->move[3] = 0;	
	else if (keycode == 123)
		data->move[4] = 0;
	else if (keycode == 124)
		data->move[5] = 0;
	else if (keycode == 53)
		exit(0);
	return (0);
}

int	routine(t_data *data)
{
	//ft_move(data)
	//ft_raycasting(data);
	//ft_mlx_init(data);
	create_wall(data);
	(void)data;
	return 0;
}

int start_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx_ptr, WIDTH, 
 	HEIGHT, "Cub3D");

	init_textures(data);
	create_background(data);
	mlx_hook(data->mlx_window, 2, 0, key_press, data);
	mlx_hook(data->mlx_window, 3, 0, key_break, data);
	mlx_hook(data->mlx_window, 17, 1L << 2, x_close, data);
	mlx_loop_hook(data->mlx_ptr, routine, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	return (0);
}






