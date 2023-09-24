/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:41:23 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/24 19:32:54 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == 13)
		data->move[0] = 1;
	else if (keycode == 1)
		data->move[1] = 1;
	else if (keycode == 0)
		data->move[2] = 1;
	else if (keycode == 2)
		data->move[3] = 1;
	else if (keycode == 123)
		data->move[4] = 1;
	else if (keycode == 124)
		data->move[5] = 1;
	if (keycode == 53)
	{
		free_game(data);
		exit(0);
	}
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == 13)
		data->move[0] = 0;
	else if (keycode == 1)
		data->move[1] = 0;
	else if (keycode == 0)
		data->move[2] = 0;
	else if (keycode == 2)
		data->move[3] = 0;
	else if (keycode == 123)
		data->move[4] = 0;
	else if (keycode == 124)
		data->move[5] = 0;
	return (0);
}
