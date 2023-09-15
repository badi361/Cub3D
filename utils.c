/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:12:22 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/15 19:32:38 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int is_true(char c)
{
	if(c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

int is_false(char c)
{
	if (c == '1' || c == 'O' || c == 'N' || c == 'E' || c == 'W' || c == 'S' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	path_helper(char a, char b, t_data *data)
{
	int	i;
	int flag;

	flag = 0;
	i = 0;
	char **str;
	while ( data -> image_path[i] != '.' && data->image_path[i] != '\n')
		i++;
	if (a == 'S' && b == 'O')
		data->south.path = ft_strjoin(data->south.path, &data -> image_path[i]);
	if (a == 'N' && b == 'O')
		data->north.path = ft_strjoin(data->north.path, &data -> image_path[i]);
	if (a == 'W' && b == 'E')
		data->west.path = ft_strjoin(data->west.path, &data -> image_path[i]);
	if (a == 'E' && b == 'A')
		data->east.path = ft_strjoin(data->east.path, &data -> image_path[i]);
	if (a == 'F' && b == ' ')
	{
		i = 0;
		while (data->image_path[i])
		{
			if (data->image_path[i] == ',')
			{
				if (ft_isdigit(data->image_path[++i]))
					flag += 1;
			}
			if (flag == 2)
				break ;
			i++;
		}
		if (flag != 2) // hata yaz
			return (1);
		str = ft_split(&data->image_path[2], ',');
		data->floor.r = ft_atoi(str[0]);
		data->floor.g = ft_atoi(str[1]);
		data->floor.b = ft_atoi(str[2]);
	}
	if (a == 'C' && b == ' ')
	{
		i = 0;
		while (data->image_path[i])
		{
			if (data->image_path[i] == ',')
			{
				if (ft_isdigit(data->image_path[++i]))
					flag += 1;
			}
			if (flag == 2)
				break ;
			i++;
		}
		if (flag != 2) // hata yaz
			return (1);
		str = ft_split(&data->image_path[2], ',');
		data->sky.r = ft_atoi(str[0]);
		data->sky.g = ft_atoi(str[1]);
		data->sky.b = ft_atoi(str[2]);
		return (3);
	}
	return (0);
}


