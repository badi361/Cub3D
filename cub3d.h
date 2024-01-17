/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:38:03 by yturgut           #+#    #+#             */
/*   Updated: 2024/01/17 18:21:14 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define WIDTH SCREEN_WIDTH
# define HEIGHT SCREEN_HEIGHT
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "./mlx/mlx.h"
# include "./ft_libft/libft.h" 
# include "./ft_get_next_line/get_next_line.h" 

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
	int	g;
	int	b;
}	t_color;

typedef struct s_data
{
	int			mapy_size;
	int			cub_size;
	int			start_player_x;
	int			start_player_y;
	int			player_size;
	int			zero_size;
	void		*mlx_ptr;
	char		**map;
	char		*image_path;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	int			hit;
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			move[6];
	double		move_speed;
	double		rot_speed;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			draw_start;
	int			draw_end;
	int			line_height;
	int			side;
	char		player_r;
	double		perp_wall_dist;
	double		raydir_x;
	double		raydir_y;
	t_texture	north;
	t_texture	east;
	t_texture	west;
	t_texture	south;
	t_texture	gun;
	t_img		img;
	t_color		floor;
	t_color		sky;
	int			tex_x;
	int			tex_y;
	double		step;
	double		wall_x;
	int			floorc;
	int			skyc;
	double		tex_pos;
	int			**int_map;
	int			arg_count;
	int			flager;
	char		a_char;
	char		b_char;
	int			so_flag;
	int			no_flag;
	int			we_flag;
	int			ea_flag;
	int			f_flag;
	int			c_flag;

}	t_data;

int				arg_control(int ac, char **av);
int				get_map(char *av, t_data *data);
void			get_map2(char *av, t_data *data);
void			map_check(t_data *data);
int				wall_check(t_data *data);
int				wall_check_s_e(t_data *data);
int				is_true(char c);
int				player_check(t_data *data);
int				size_control(t_data *data);
void			path_helper(char a, char b, t_data *data);
void			data_init(t_data *data);
void			start_init(t_data *data);
int				is_map_one(t_data *data);
int				is_false(char c);
void			start_img(t_data *data);
void			open_textures(t_data *data);
void			img_pix_put(t_img *img, int x, int y, int color);
void			create_background(t_data *data);
void			move_forward(t_data *data);
void			move_back(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);
void			rotate_right(t_data *data);
void			rotate_left(t_data *data);
int				key_press(int keycode, t_data *data);
int				key_release(int keycode, t_data *data);
void			player_move(t_data *data);
int				ray_casting(t_data *data);
int				create_trgb(int t, int r, int g, int b);
unsigned int	get_pixel_in_tex(t_texture tex, int x, int y);
int				change_map(t_data *data);
void			fill_player_dir(t_data *data, double x, double y);
void			player_first_rotate(t_data *data);
int				x_close(int keycode, t_data *data);
void			free_game(t_data *data);
void			calc_texture_pixel_color(t_data *data);
void			ft_free(char **str);
void			ft_error_msg(char *str);
void			c_space_func(int flag, char **str, t_data *data);
void			f_space_func(int flag, char **str, t_data *data);
void			rgb_ctrl(t_data *data);
void			rgb_ctrl_2(t_data *data);
void			ft_map_check_helper(int i, int j, t_data *data);
void			player_rotate_helper(t_data *data);
int				change_map_malloc(t_data *data);
char			*ft_strjoin3(char const *s1, char const *s2);
void			ft_get_map_helper(t_data *data);
void			get_map_helper_2(t_data *data, int fd);
void			last_colomn_ctrl(t_data *data, int fd);
void			flag_ctrl(int flag, int flag2);
void			get_rgb(char **str, t_data *data);
void			get_rgb_2(char **str, t_data *data);
void			path_helper_v2(int flag, t_data *data, int i);
void			is_map_one2(t_data *data);
void			f_ctrl(t_data *data, int flag, char **str);
void			c_ctrl(t_data *data, int flag, char **str);
void			get_so(t_data *data, int i);
void			get_no(t_data *data, int i);
void			get_we(t_data *data, int i);
void			get_ea(t_data *data, int i);

#endif