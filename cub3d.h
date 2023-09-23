/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:38:03 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/23 17:38:21 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H


#define screenWidth 1920
#define screenHeight 1080 // 350 730 840 859 

# define WIDTH screenWidth
# define HEIGHT screenHeight
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
#include <sys/time.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h" 
# include "./get_next_line/get_next_line.h" 


typedef struct s_texture{
	void	*image;
	char	*path;
	char	*data;
	int		use;
	int		w;
	int		h;
	int		bpp;
	int		sizeline;
	int		endian;
}	t_texture;

typedef struct s_img{
	void	*window;
	int		*image;
	char	*data;
	int		bpp; 
	int		sizeline;
	int		endian; 
}	t_img;

typedef struct color
{
	int	r;
	int g;
	int b;
}	t_color;




typedef struct s_data
{
	int mapy_size;
	int cub_size;
	int start_player_x;
	int start_player_y;
	int player_size;
	int zero_size;
	void	*mlx_ptr;
	char **map; 
	char *image_path;




	void *mlx;
	void *win;
	int x;
	int y;
	int move[6];
	double moveSpeed;
	double rotSpeed;
	double posX,posY;  //x and y start position
	double dirX,dirY; //initial direction vector
	double planeX,planeY; //the 2d raycaster version of camera plane
	int drawStart;
	int drawEnd;
	int lineHeight;
	int side;
	char player_r;
	double perpWallDist;
	double rayDirX;
	double rayDirY;
	t_texture north;
	t_texture east;
	t_texture west;
	t_texture south;
	t_texture gun;
	t_img img;
	t_color		floor;
	t_color		sky;
	int texX;
	int texY;
	double step;
	double wallX;
	int floorc;
	int skyc;
	double texPos;
	int **worldMap;
	

} t_data;


int		arg_control(int ac, char **av);
int		get_map(char *av, t_data *data);
void	get_map2(char *av, t_data *data);
int		map_check(t_data *data);
int		wall_check(t_data *data);
int		wall_check_s_e(t_data *data);
int		is_true(char c);
int		player_check(t_data *data);
int		size_control(t_data *data);
int		path_helper(char a, char b, t_data *data);
int		ft_exit(int key, t_data *data); //bak
void	data_init(t_data *data);
void	start_init(t_data *data);

int		is_map_one(t_data *data);
int		is_false(char c);
void	start_img(t_data *data);
void	open_textures(t_data *data);
void	img_pix_put(t_img *img, int x, int y, int color);
void	create_background(t_data *data);
void	move_forward(t_data *data);
void	move_back(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	rotate_right(t_data *data);
void	rotate_left(t_data *data);
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
void	player_move(t_data *data);
int		ray_casting(t_data *data);
int		create_trgb(int t, int r, int g, int b);
void	put_vertical(t_data *data, int x, int start, int end, int color);
unsigned int	get_pixel_in_tex(t_texture tex, int x, int y);
void change_map(t_data *data);
void	fill_player_dir(t_data *data, double x, double y);
void	player_first_rotate(t_data *data);
int	x_close(int keycode, t_data *data);
void free_game(t_data *data);






#endif