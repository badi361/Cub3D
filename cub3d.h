/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:49:17 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/14 19:22:45 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h" 
# include "./get_next_line/get_next_line.h" 

typedef struct cub3d
{
	int mapx_size; //
	int mapy_size;
	int start_player_x;
	int start_player_y;
	int player_size;
	char **map;
	char *map_full; //
}				t_data;


int		arg_control(int ac, char **av);
int		get_map(char *av, t_data *data);
void	get_map2(char *av, t_data *data);
int		map_check(t_data *data);
int		wall_check(t_data *data);
int		wall_check_s_e(t_data *data);
int		is_true(char c);
int		player_check(t_data *data);

#endif