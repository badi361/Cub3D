/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:56:28 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/24 19:48:01 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_check(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (data->map[++j])
	{
		i = -1;
		while (data->map[j][++i])
		{
			if (data->map[j][i] == ' ' || data->map[j][i] == '1'
				|| data->map[j][i] == '0' || data->map[j][i] == '\n')
			{
				if (data->map[j][i] == '0')
					data -> zero_size++;
			}
			else if (data->map[j][i] == 'N' || data->map[j][i] == 'E'
				|| data->map[j][i] == 'W' || data->map[j][i] == 'S')
				ft_map_check_helper(i, j, data);
			else
				ft_error_msg ("INVALİD MAP ERROR");
			i++;
		}
	}
}

int	wall_check(t_data *data)
{
	int	i;
	int	j;

	j = 1;
	while (j < data->mapy_size - 1)
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == '0')
			{
				if (is_true(data->map[j][i + 1]) || is_true(data->map[j][i - 1])
					|| is_true(data->map[j + 1][i])
					|| is_true(data->map[j - 1][i]))
					ft_error_msg("WALL - 0 - ERROR");
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	wall_check_s_e(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i] != '\n')
	{
		if (data->map[0][i] == '0')
		{
			printf("WALL ERROR5\n");
			return (1);
		}
		i++;
	}
	i = 0;
	if (data->map[data ->mapy_size - 1] == NULL)
		data ->mapy_size--;
	while (data->map[data ->mapy_size - 1][i])
	{
		if (data->map[data ->mapy_size - 1][i] == '0')
			ft_error_msg("WALL - 6 - ERROR");
		i++;
	}
	return (0);
}

int	player_check(t_data *data)
{
	int	x;
	int	y;

	x = data ->start_player_x;
	y = data->start_player_y;
	if (y == data->mapy_size - 1 || y == 0)
		ft_error_msg("PLAYER - 1 - ERROR");
	if (x == 0)
		ft_error_msg("PLAYER - 2 - ERROR");
	if (is_true(data->map[y][x - 1]) || is_true(data->map[y][x + 1])
		|| is_true(data->map[y + 1][x]) || is_true(data->map[y - 1][x]))
		ft_error_msg("PLAYER - 3 - ERROR");
	return (0);
}

int	size_control(t_data *data)
{
	if (data ->mapy_size < 3)
		ft_error_msg("MAP SİZE ERROR");
	if (data -> player_size != 1)
		ft_error_msg("INVALID PLAYER ERROR");
	if (data ->zero_size == 0 && data -> player_size == 0)
		ft_error_msg("MAP SİZE IS 0 ERROR");
	return (0);
}
