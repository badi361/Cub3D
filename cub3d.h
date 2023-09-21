/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:38:03 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/21 16:01:15 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H



#define mapWidth 24
#define mapHeight 24
#define screenWidth 1920
#define screenHeight 1080
extern int worldMap[mapWidth][mapHeight];
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






typedef struct s_data
{
	void *mlx;
	void *win;
	int move[6];
	double moveSpeed;
	double rotSpeed;
	double posX,posY;  //x and y start position
	double dirX,dirY; //initial direction vector
	double planeX,planeY; //the 2d raycaster version of camera plane
	t_texture north;
	t_texture east;
	t_texture west;
	t_texture south;
	t_img img;
	
	int floorc;
	int skyc;

} t_data;




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




#endif