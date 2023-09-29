/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:15:48 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/29 17:32:59 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_ea(t_data *data, int i)
{
	data->ea_flag += 1;
	if (data->ea_flag != 1)
		ft_error_msg("2 time EA Error");
	data->east.path = ft_strjoin(data->east.path, &data -> image_path[i]);
}
