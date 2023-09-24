/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:12:22 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/24 21:47:26 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_true(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

int	is_false(char c)
{
	if (c == '1' || c == 'O' || c == 'N' || c == 'E'
		|| c == 'W' || c == 'S' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	path_helper(char a, char b, t_data *data)
{
	int		i;
	int		flag;
	char	**str;

	flag = 0;
	i = 0;
	while (data->image_path[i] != '.' && data->image_path[i] != '\n')
		i++;
	if (a == 'S' && b == 'O')
		data->south.path = ft_strjoin(data->south.path, &data -> image_path[i]);
	else if (a == 'N' && b == 'O')
		data->north.path = ft_strjoin(data->north.path, &data -> image_path[i]);
	else if (a == 'W' && b == 'E')
		data->west.path = ft_strjoin(data->west.path, &data -> image_path[i]);
	else if (a == 'E' && b == 'A')
		data->east.path = ft_strjoin(data->east.path, &data -> image_path[i]);
	else if (a == 'F' && b == ' ')
		f_space_func(flag, str, data);
	else if (a == 'C' && b == ' ')
		c_space_func(flag, str, data);
	else
		ft_error_msg("ARGUMANT - 0 - ERROR");
	data->arg_count += 1;
}

int	x_close(int keycode, t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.image);
	exit(0);
	return (0);
}

void	f_space_func(int flag, char **str, t_data *data)
{
	int	i;

	i = -1;
	while (data->image_path[++i])
	{
		if (data->image_path[i] == ',')
		{
			i++;
			while (data->image_path[i] == ' ' || data->image_path[i] == '\t')
				i++;
			if (ft_isdigit(data->image_path[i]))
				flag += 1;
		}
		if (flag == 2)
			break ;
	}
	if (flag != 2)
		ft_error_msg("RGB - 0 - ERROR");
	str = ft_split(&data->image_path[2], ',');
	data->floor.r = ft_atoi(str[0]);
	data->floor.g = ft_atoi(str[1]);
	data->floor.b = ft_atoi(str[2]);
	ft_free(str);
	rgb_ctrl_2(data);
}
