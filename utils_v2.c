/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:15:17 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/28 18:16:39 by bguzel           ###   ########.fr       */
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
	int	flag2;

	i = data->flager + 2;
	flag2 = 0;
	while (data->image_path[i] == ' ')
		i++;
	data->flager = i;
	if (data->image_path[i] == ',')
		ft_error_msg("',' Error");
	while (data->image_path[++i])
	{
		if (data->image_path[i] == ',')
		{
			flag2 += 1;
			i++;
			while (data->image_path[i] == ' ' || data->image_path[i] == '\t')
				i++;
			if (ft_isdigit(data->image_path[i]))
				flag += 1;
		}
	}
	flag_ctrl(flag, flag2);
	get_rgb(str, data);
}

void	rgb_ctrl(t_data *data)
{
	if (data->sky.r < 0 || data->sky.r > 255)
		ft_error_msg("RGB - 5 - Error");
	if (data->sky.g < 0 || data->sky.g > 255)
		ft_error_msg("RGB - 6 - Error");
	if (data->sky.b < 0 || data->sky.b > 255)
		ft_error_msg("RGB - 7 - Error");
}

void	rgb_ctrl_2(t_data *data)
{
	if (data->floor.r < 0 || data->floor.r > 255)
		ft_error_msg("RGB - 1 - Error");
	if (data->floor.g < 0 || data->floor.g > 255)
		ft_error_msg("RGB - 2 -Error");
	if (data->floor.b < 0 || data->floor.b > 255)
		ft_error_msg("RGB - 3 - Error");
}
