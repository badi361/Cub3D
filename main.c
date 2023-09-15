/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:48:48 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/15 19:37:10 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void data_init(t_data *data)
{
	data -> mapx_size = 0;
	data -> mapy_size = 0;
	data -> cub_size = 0;
	data -> player_size = 0;
	data -> zero_size = 0;
	data-> map = NULL;
	data -> image_path = NULL;
	data ->north.path = NULL;
	data ->east.path = NULL;
	data ->south.path = NULL;
	data ->west.path = NULL;
	data ->north.image = NULL;
	data ->west.image = NULL;
	data ->east.image = NULL;
	data ->south.image = NULL;
	data->floor.r = 0;
	data->floor.g = 0;
	data->floor.b = 0;
	data->sky.r = 0;
	data->sky.g = 0;
	data->sky.b = 0;
}

int main(int ac, char **av)
{
	t_data *data;


	data = malloc(sizeof(t_data));
	data_init(data);
	if (arg_control(ac, av))
		exit(0);

	if(get_map(av[1], data))
		exit(0);
	
	// int i = 0;
	// while (data -> map[i])
	// {
	// 	printf("%s", data -> map[i]);
	// 	i++;
	// }
	

	if(map_check(data))
		exit(0);
	if(size_control(data))
		exit(0);
	if(wall_check_s_e(data))
		exit(0);
	if(wall_check(data))
		exit(0);
	if(player_check(data))
		exit(0);
	if(is_map_one(data))
		exit(0);
		
	printf("OPENNED\n");
	start_game(data);
	

	
	return 0;	
    // void    *mlx;
    // void    *mlx_win;
    // mlx = mlx_init();
    // mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    // mlx_loop(mlx);
}