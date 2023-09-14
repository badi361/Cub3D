/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:56:28 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/14 19:28:37 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_check(t_data *data)
{
	int	i;
    int j;

    j = 0;
    while (data->map[j])
    {
        i = 0;
        while(data->map[j][i])
        {
			if (data->map[j][i] == ' ' || data->map[j][i] == '\t' || data->map[j][i] == '1' 
			|| data->map[j][i] == '0' || data->map[j][i] == '\n')           
				i++;
			else if (data->map[j][i] == 'N' || data->map[j][i] == 'E' || data->map[j][i] == 'W' 
			|| data->map[j][i] == 'S')    
			{
				data -> start_player_x = i;
				data -> start_player_y = j;
                i++;
                data -> player_size++;
             
            }
            else
            {
                printf("INVALID MAP");
                return (1);
            }
        }   
	
		j++;
    }
	if (data -> player_size != 1)
	{
		printf("INVALID PLAYER");
		return (1);
	}
    return (0);
}

int wall_check(t_data *data)
{
	int	i;
	int	j;

	
	j = 1;
	while (j < data->mapy_size - 1)
	{
		i = 0;
		while (data->map[j][i])
		{
			if(data->map[j][i] == '0')
			{
				if(data->map[j][i + 1] == ' ' || data->map[j][i + 1] == '\t' || data->map[j][i + 1] == '\n' 
				|| data->map[j][i + 1] == '\0' || data->map[j + 1] == NULL)
				{
					printf("WALL ERROR1");
					return (1);
				}
				else if(data->map[j][i - 1] == ' ' || data->map[j][i - 1] == '\t' || data->map[j][i - 1] == '\n' 
				|| data->map[j][i - 1] == '\0' || data->map[j + 1] == NULL)
				{
					printf("WALL ERROR2");
					return (1);
				}
				else if(data->map[j + 1][i] == ' ' || data->map[j + 1][i] == '\t' || data->map[j + 1][i] == '\n' 
				|| data->map[j + 1][i] == '\0' || data->map[j + 1] == NULL)
				{
					printf("WALL ERROR3");
					return (1);
				}
				else if(data->map[j - 1][i] == ' ' || data->map[j - 1][i] == '\t' || data->map[j - 1][i] == '\n' 
				|| data->map[j - 1][i] == '\0' || data->map[j + 1] == NULL)
				{
					printf("WALL ERROR4");
					return (1);
				}
			}
			i++;
		}
		j++;
	}
	return 0;
}

int wall_check_s_e(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i] != '\n')
	{
		if(data->map[0][i] == '0')
		{
			printf("WALL ERROR5");
			return (1);
		}
		i++;
	}
	i = 0;
	while (data->map[data ->mapy_size - 1][i] != '\0')
	{
		if(data->map[data ->mapy_size - 1][i] == '0')
		{
			printf("WALL ERROR6");
			return (1);
		}
		i++;
	}
	return  (0);
}

int player_check(t_data *data)
{
	int	x;
	int	y;

	x = data ->start_player_x;
	y = data->start_player_y;
	if(y == data ->mapy_size  - 1 || y == 0 )
	{
		printf("PLAYER ERROR1");
		return (1);
	}
	if(x == 0)
	{
		printf("PLAYER ERROR3");
		return (1);
	}
	if(is_true(data->map[y][x - 1]) || is_true(data->map[y][x + 1]) || is_true(data->map[y + 1][x]) || is_true(data->map[y - 1][x]))
	{
		printf("PLAYER ERROR2");
		return (1);
	}
	return (0);
}