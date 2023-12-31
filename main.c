/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:35:04 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/29 16:40:31 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_game_loop(t_data *data)
{
	player_move(data);
	ray_casting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.image, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->gun.image, 900, 430);
	return (0);
}

void	start_game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3d");
	start_init(data);
	start_img(data);
	open_textures(data);
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 3, 0, key_release, data);
	mlx_hook(data->win, 17, 1L << 2, x_close, data);
	mlx_loop_hook(data->mlx, &ft_game_loop, data);
	mlx_loop(data->mlx);
}

void	before_game(t_data *data)
{
	map_check(data);
	if (size_control(data))
		exit(0);
	if (wall_check_s_e(data))
		exit(0);
	if (wall_check(data))
		exit(0);
	if (player_check(data))
		exit(0);
	if (is_map_one(data))
		exit(0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		data = malloc(sizeof(t_data));
		data->we_flag = 0;
		data->ea_flag = 0;
		data_init(data);
		if (arg_control(ac, av))
			exit(0);
		if (get_map(av[1], data))
			exit(0);
		before_game(data);
		if (change_map_malloc(data))
			ft_error_msg("Error");
		if (change_map(data))
			exit(0);
		player_first_rotate(data);
		start_game(data);
	}
	else
		ft_error_msg("ac error");
	return (0);
}
