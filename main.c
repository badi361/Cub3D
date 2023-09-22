/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:35:04 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/22 20:30:40 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_game_loop(t_data *data)
{
	ray_casting(data);
	player_move(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.image, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->gun.image, 0 , 0);
	
	return 0;
}
 
void start_game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, screenWidth, screenHeight, "Cub3d");
	start_init(data);

	start_img(data);
	open_textures(data);

	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 3, 0, key_release, data);
	//	mlx_hook(data->img.window, 17, 1L << 2, x_close, data); //unutma
	mlx_loop_hook(data->mlx, &ft_game_loop, data);
	mlx_loop(data->mlx);
}

void before_game(t_data *data)
{
	
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
}

int main(int ac, char **av)
{		
	t_data *data;
	ac = 2; //sil sil sil
	if (ac == 2)
	{	
		data=  malloc(sizeof(t_data));
		data_init(data);
		if (arg_control(ac, av))
		exit(0);
		if(get_map(av[1], data))
		exit(0);
		before_game(data);
		change_map(data);
		start_game(data);
		mlx_destroy_window(data->mlx, data->win);
	}
	return 0;
}



