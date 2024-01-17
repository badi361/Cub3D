/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:57:20 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/29 17:33:18 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	arg_control(int ac, char **av)
{
	int	len;

	if (ac != 2)
		ft_error_msg("AC Error");
	len = ft_strlen(av[1]) - 1;
	if ((av[1][len] != 'b' && av[1][len - 1] != 'u'
		&& av[1][len - 2] != 'c' && av[1][len - 3] != '.')
		|| ft_strlen(av[1]) < 5)
		ft_error_msg("MAP IS NOT .CUB Error");
	return (0);
}

void	is_map_one2(t_data *data)
{
	int	i;
	int	j;
	int	flag;
	int	len;

	j = 0;
	flag = 0;
	while (data ->map[j])
	{
		i = 0;
		len = 0;
		while (data -> map[j][i] && data -> map[j][i] != '\n')
		{
			if (data->map[j][i] == ' ')
				len++;
			i++;
		}
		if ((ft_strlen(data->map[j]) == (size_t)len + 1))
			ft_error_msg("MAP DIVISION2 Error");
		j++;
	}
}

int	is_map_one(t_data *data)
{
	int	i;
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	while (data ->map[j])
	{
		i = 0;
		while (data -> map[j][i])
		{
			if (data->map[j][0] == '\n')
				flag++;
			if (is_false(data->map[j][i]) == 1 && flag != 0)
				ft_error_msg("MAP DIVISION Error");
			i++;
		}
		j++;
	}
	is_map_one2(data);
	return (0);
}
