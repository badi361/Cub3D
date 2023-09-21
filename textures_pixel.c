/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:24:11 by bkarlida          #+#    #+#             */
/*   Updated: 2023/09/20 18:08:08 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void create_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < screenHeight / 2)
	{
		i = 0;
		while (i < screenWidth)
		{
			img_pix_put(&data->img, i, j, data->skyc);
			i++;
		}
		j++;
	}
	
	while (j < screenHeight)
	{
		i = 0;
		while (i < screenWidth)
		{
			img_pix_put(&data->img, i, j, data->floorc);
			i++;
		}
		j++;
	}
}