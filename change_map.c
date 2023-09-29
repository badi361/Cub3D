/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:47:14 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/29 17:31:10 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	change_map_malloc(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->int_map = malloc(sizeof(int *) * data->mapy_size);
	if (!data->int_map)
		return (1);
	while (j < data->mapy_size)
	{
		i = 0;
		while (data->map[j][i] && data->map[j][i] != '\n')
			i++;
		data->int_map[j] = malloc(sizeof(int) * i);
		if (!data->int_map[j])
			return (1);
		j++;
	}
	return (0);
}

int	change_map(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (++j < data->mapy_size)
	{
		i = 0;
		while (data->map[j][i] && data->map[j][i] != '\n')
		{
			if (data->map[j][i] == '0')
				data->int_map[j][i] = 0;
			else if (data->map[j][i] == '1')
				data->int_map[j][i] = 1;
			else if (data->map[j][i] == 'N' || data->map[j][i] == 'W'
				|| data->map[j][i] == 'E' || data->map[j][i] == 'S')
				data->int_map[j][i] = 0;
			else if (data->map[j][i] == ' ')
				data->int_map[j][i] = 2;
			i++;
		}
		free(data->map[j]);
	}
	free(data->map);
	return (0);
}

void	get_rgb_2(char **str, t_data *data)
{
	str = ft_split(&data->image_path[data->flager], ',');
	data->floor.r = ft_atoi(str[0]);
	data->floor.g = ft_atoi(str[1]);
	data->floor.b = ft_atoi(str[2]);
	ft_free(str);
	rgb_ctrl_2(data);
}

void	path_helper_v2(int flag, t_data *data, int i)
{
	char	a;
	char	b;

	a = data->a_char;
	b = data->b_char;
	while (data->image_path[i] != '.' && data->image_path[i] != '\n')
	{
		if (data->image_path[i] != ' ')
			ft_error_msg("Direction Error");
		i++;
		flag = 1;
	}
	if (a == 'S' && b == 'O' && flag == 1)
		get_so(data, i);
	else if (a == 'N' && b == 'O' && flag == 1)
		get_no(data, i);
	else if (a == 'W' && b == 'E' && flag == 1)
		get_we(data, i);
	else if (a == 'E' && b == 'A' && flag == 1)
		get_ea(data, i);
	else
		ft_error_msg("ARGUMANT - 0 - Error");
	data->arg_count += 1;
}
