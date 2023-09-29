/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:11:01 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/29 17:31:52 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c_ctrl(t_data *data, int flag, char **str)
{
	data->arg_count += 1;
	data->c_flag += 1;
	if (data->c_flag != 1)
		ft_error_msg("2 times C Error");
	c_space_func(flag, str, data);
}

void	f_ctrl(t_data *data, int flag, char **str)
{
	data->arg_count += 1;
	data->f_flag += 1;
	if (data->f_flag != 1)
		ft_error_msg("2 times f Error");
	f_space_func(flag, str, data);
}

void	get_so(t_data *data, int i)
{
	data->so_flag += 1;
	if (data->so_flag != 1)
		ft_error_msg("2 time SO Error");
	data->south.path = ft_strjoin(data->south.path, &data -> image_path[i]);
}

void	get_no(t_data *data, int i)
{
	data->no_flag += 1;
	if (data->no_flag != 1)
		ft_error_msg("2 time NO Error");
	data->north.path = ft_strjoin(data->north.path, &data -> image_path[i]);
}

void	get_we(t_data *data, int i)
{
	data->we_flag += 1;
	if (data->we_flag != 1)
		ft_error_msg("2 time WE Error");
	data->west.path = ft_strjoin(data->west.path, &data -> image_path[i]);
}
