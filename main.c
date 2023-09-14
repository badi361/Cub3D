/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:48:48 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/14 19:27:33 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void data_init(t_data *data)
{
	data -> mapx_size = 0;
	data -> mapy_size = 0;
	data -> player_size = 0;
	data-> map = NULL;
	data -> map_full = NULL;
}

int main(int ac, char **av)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data_init(data);
	if (arg_control(ac, av) || get_map(av[1], data) || map_check(data) || wall_check_s_e(data))
		exit(0);
	wall_check(data);
	player_check(data);
	
	
	
	
    // void    *mlx;
    // void    *mlx_win;
    // mlx = mlx_init();
    // mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    // mlx_loop(mlx);
}