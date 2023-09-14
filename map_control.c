/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:57:20 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/14 18:40:49 by bguzel           ###   ########.fr       */
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
