/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_to_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:24:11 by yturgut           #+#    #+#             */
/*   Updated: 2023/09/25 20:35:00 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->data + (y * img->sizeline + x * (img->bpp / 8));
	*(int *)pixel = color;
}

unsigned int	get_pixel_in_tex(t_texture tex, int x, int y)
{
	char	*dst;

	dst = tex.data + (y * tex.sizeline + x * (tex.bpp / 8));
	return (*((unsigned int *)dst));
}
