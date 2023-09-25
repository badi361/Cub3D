/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:56:28 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/25 16:32:44 by yturgut          ###   ########.fr       */
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
		i = 0;
		while (data->map[j][i])
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
				ft_error_msg ("INVALID MAP Error");
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
					ft_error_msg("WALL - 0 - Error");
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
			printf("WALL Error5\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (data->map[data->mapy_size - 1][i])
	{
		if (data->map[data ->mapy_size - 1][i] == '0')
			ft_error_msg("WALL - 6 - Error");
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
		ft_error_msg("PLAYER - 1 - Error");
	if (x == 0)
		ft_error_msg("PLAYER - 2 - Error");
	if (is_true(data->map[y][x - 1]) || is_true(data->map[y][x + 1])
		|| is_true(data->map[y + 1][x]) || is_true(data->map[y - 1][x]))
		ft_error_msg("PLAYER - 3 - Error");
	return (0);
}

int	size_control(t_data *data)
{
	if (data ->mapy_size < 3)
		ft_error_msg("MAP SIZE Error");
	if (data -> player_size != 1)
		ft_error_msg("INVALID PLAYER Error");
	if (data ->zero_size == 0 && data -> player_size == 0)
		ft_error_msg("MAP SIZE IS 0 Error");
	return (0);
}
