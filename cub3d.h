/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:49:17 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/16 19:42:07 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# define WIDTH 800
# define HEIGHT 600

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h" 
# include "./get_next_line/get_next_line.h" 

typedef struct texture
{
	void *image;
	char *path;
	int w;
	int h;
}	t_texture;

typedef struct color
{
	int	r;
	int g;
	int b;
}	t_color;
typedef struct cub3d
{
	int mapx_size; //
	int mapy_size;
	int cub_size;
	int start_player_x;
	int start_player_y;
	int player_size;
	int zero_size;
	void	*mlx_ptr;
	void	*mlx_window;
	char **map; //
	char *image_path;
	int move[6];
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	t_color		floor;
	t_color		sky;
}				t_data;


int		arg_control(int ac, char **av);
int		get_map(char *av, t_data *data);
void	get_map2(char *av, t_data *data);
int		map_check(t_data *data);
int		wall_check(t_data *data);
int		wall_check_s_e(t_data *data);
int		is_true(char c);
int		player_check(t_data *data);
int		size_control(t_data *data);
int		start_game(t_data *data);
int		path_helper(char a, char b, t_data *data);
int		ft_exit(int key, t_data *data);


int		is_map_one(t_data *data);
int		is_false(char c);
int	routine(t_data *data);//a
int start_game(t_data *data); //a
void	init_textures(t_data *data);
int	ft_create_trgb(int t, int r, int g, int b);//a
void	create_background(t_data *data);
void	create_wall(t_data *data);
#endif