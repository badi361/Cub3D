/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:32:32 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/23 18:27:07 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tex_paths_2(t_data *data)
{
	if (data->north.path)
		free(data->north.path);
	if (data->south.path)
		free(data->south.path);
	if (data->west.path)
		free(data->west.path);
	if (data->east.path)
		free(data->east.path);
}

void free_map2(t_data *data)
{
	int i;

	i = data->mapy_size - 1;
	while (i >= 0) 
	{
		free(data->worldMap[i]);
		i--;
	}
	free(data->worldMap);
}

void free_game(t_data *data)
{	
	free_map2(data);
	free_tex_paths_2(data);
}
