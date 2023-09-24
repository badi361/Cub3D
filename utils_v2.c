/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:15:17 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/24 20:15:45 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error_msg(char *str)
{
	printf("%s\n", str);
	exit(0);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	c_space_func(int flag, char **str, t_data *data)
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
		ft_error_msg("RGB - 4 - ERROR");
	str = ft_split(&data->image_path[2], ',');
	data->sky.r = ft_atoi(str[0]);
	data->sky.g = ft_atoi(str[1]);
	data->sky.b = ft_atoi(str[2]);
	ft_free(str);
	rgb_ctrl(data);
}

void	rgb_ctrl(t_data *data)
{
	if (data->sky.r < 0 || data->sky.r > 255)
		ft_error_msg("RGB - 5 - ERROR");
	if (data->sky.g < 0 || data->sky.g > 255)
		ft_error_msg("RGB - 6 - ERROR");
	if (data->sky.b < 0 || data->sky.b > 255)
		ft_error_msg("RGB - 7 - ERROR");
}

void	rgb_ctrl_2(t_data *data)
{
	if (data->floor.r < 0 || data->floor.r > 255)
		ft_error_msg("RGB - 1 - ERROR");
	if (data->floor.g < 0 || data->floor.g > 255)
		ft_error_msg("RGB - 2 -ERROR");
	if (data->floor.b < 0 || data->floor.b > 255)
		ft_error_msg("RGB - 3 - ERROR");
}
