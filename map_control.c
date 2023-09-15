/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:57:20 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/15 19:28:21 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	arg_control(int ac, char **av)
{
	int	len;
	
	if (ac != 2)
	{
		printf("AC_ERROR");
		return (1);
	}
	
	len = ft_strlen(av[1]) - 1;
	
	if ((av[1][len] != 'b' && av[1][len - 1] != 'u' && av[1][len - 2] != 'c' && av[1][len - 3] != '.') || ft_strlen(av[1]) < 4)
	{
	
		printf("MAP NAME IS NOT .CUB");
		return (1);
	}
	return (0);
}

int is_map_one(t_data *data)
{
	int	i;
	int	j;
	int flag;

	j = 0;
	flag = 0;
	while (data ->map[j])
	{
		i = 0;
		while (data -> map[j][i])
		{
			if(data->map[j][0] == '\n')
			{
				flag++;
			}
			if(is_false(data->map[j][i]) == 1 && flag != 0)
			{
				printf("Map Division ERROR\n");
				exit(0);
			}
			i++;
		}
		j++;
		
	}
	return (0);
	
}
