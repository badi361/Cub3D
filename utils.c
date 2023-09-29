/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:12:22 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/29 17:11:35 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_true(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

int	is_false(char c)
{
	if (c == '1' || c == 'O' || c == 'N' || c == 'E'
		|| c == 'W' || c == 'S' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	path_helper(char a, char b, t_data *data)
{
	int		i;
	int		flag;
	char	**str;

	str = NULL;
	flag = 0;
	i = data->flager + 2;
	data->a_char = a;
	data->b_char = b;
	if (a == 'F' && b == ' ')
	{
		f_ctrl(data, flag, str);
		return ;
	}
	else if (a == 'C' && b == ' ')
	{
		c_ctrl(data, flag, str);
		return ;
	}
	path_helper_v2(flag, data, i);
}

int	x_close(int keycode, t_data *data)
{
	(void)keycode;
	(void)data;
	exit(0);
	return (0);
}

void	f_space_func(int flag, char **str, t_data *data)
{
	int	i;
	int	flag2;

	flag2 = 0;
	i = data->flager + 2;
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
	get_rgb_2(str, data);
}
